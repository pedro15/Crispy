using System;
using System.Threading;
using System.Threading.Tasks;
using System.Collections.Generic;

namespace Crispy.Client.Internal
{
    internal abstract class ContextBase<T> where T : ContextBase<T> 
    {
        public Func<string> userInputHandler = null;
        public Action<string> onContextResponse = null;
        
        public bool Running{get; private set;} = false;
        private object lockobj = new object();
        private CancellationTokenSource cancelTokenSource;
        private Dictionary<string,ICommand<T>> commandList = new Dictionary<string, ICommand<T>>();

        internal abstract ICommand<T>[] GetCommands();
        internal virtual void OnCommandNotFound(string commandToken) { }
        internal virtual void OnInitialize() { }

        public void Initialize(Func<string> userInputHandler, Action<string> onContextResponse = null)
        {
            this.userInputHandler = userInputHandler;
            this.onContextResponse = onContextResponse;
            OnInitialize();
        }

        public void Run(bool executeInBackgroundThread = false)
        {
            if (Running) return;
            
            void RunContext()
            {
                while(Running)
                {
                    string cmd = userInputHandler.Invoke();
                    if (!string.IsNullOrEmpty(cmd))
                    {
                        string[] tokens = cmd.Trim().Split(new []{ ' ' }, System.StringSplitOptions.RemoveEmptyEntries);
                        if(commandList.TryGetValue(tokens[0], out ICommand<T> command))
                        {
                            command.Execute((T)this, tokens);
                        }else 
                        {
                            OnCommandNotFound(tokens[0]);
                        }
                    }
                }
            }

            if (executeInBackgroundThread)
            {
                lock(lockobj)
                {
                    cancelTokenSource = new CancellationTokenSource();
                    _ = Task.Run(() => 
                    {
                        RunContext();
                    }).ContinueWith((t) => t.Dispose() , cancelTokenSource.Token);
                }
            }else 
            {
                RunContext();
            }
        }

        public void Stop()
        {
            Running = false;
        }
    }
}