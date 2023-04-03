using System.Collections.Generic;
using System.Reflection;
using System.Threading.Tasks;
using System.Threading;

namespace Crispy.Client.Internal.Core
{
    internal abstract class ClientContext<T> where T : ClientContext<T>
    {
        public bool IsRunning {get; private set; } = false;
        private Dictionary<string,ICommand<T>> commandsList = new Dictionary<string, ICommand<T>>();
        private List<CommandAttribute> commandsInfo = new List<CommandAttribute>();
        private CancellationTokenSource tokenSource = null;
        public IClientIOHandler iOHandler {get; private set;} = null;

        internal abstract ICommand<T>[] GetCommands();
        internal virtual void OnInitialized(){ }
        internal virtual void OnCommandNotFound(string commandName){ }

        public void Initialize(IClientIOHandler iOHandler)
        {
            this.iOHandler = iOHandler;

            ICommand<T>[] commands = GetCommands();
            for (int i = 0; i < commands.Length; i++)
            {
                ICommand<T> currentCommand = commands[i];
                if (currentCommand != null)
                {
                    CommandAttribute attr = currentCommand.GetType().GetCustomAttribute<CommandAttribute>();
                    if (attr != null && !commandsList.ContainsKey(attr.CommandName))
                    {
                        currentCommand.Initialize((T)this);
                        commandsList.Add(attr.CommandName, currentCommand);
                        commandsInfo.Add(attr);
                    }
                }
            }
            OnInitialized();
        }

        public void Run(bool useBackgrounThread = false)
        {
            if (IsRunning) return;
            
            IsRunning = true;
            
            void RunInternal()
            {
                string cmd = string.Empty;
                string[] args = null;
                ICommand<T> command = null;
                
                while(IsRunning)
                {
                    cmd = iOHandler?.GetInput();
                    if (!string.IsNullOrEmpty(cmd))
                    {
                        args = cmd.Trim().Split(new[] { ' ' } , System.StringSplitOptions.RemoveEmptyEntries);
                        if (commandsList.TryGetValue(args[0], out command)) 
                        {
                            command.Execute(args, (T)this);
                        }else 
                        {
                            OnCommandNotFound(args[0]);
                        }                       
                    }
                }
            }

            if (useBackgrounThread)
            {
                tokenSource = new CancellationTokenSource();
                _ = Task.Run(() => RunInternal() , tokenSource.Token).ContinueWith(t => t.Dispose());
            }else 
            {
                RunInternal();
            }
        }

        public void Kill()
        {
            IsRunning = false;
            tokenSource?.Cancel();
        }

        public CommandAttribute[] GetCommandsInfo()
        {
            return commandsInfo.ToArray();
        }

        public void Write(string message)
        {
            iOHandler?.OnClientResponse(message);
        }
    }
}