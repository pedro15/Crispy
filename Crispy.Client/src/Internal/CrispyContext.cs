using Crispy.Client.Internal.Core;
using Crispy.Client.Internal.Commands.Common;

namespace Crispy.Client.Internal
{
    internal class CrispyContext : ClientContext<CrispyContext>
    {
        public bool slientMode = false;

        internal override ICommand<CrispyContext>[] GetCommands()
        {
            return new ICommand<CrispyContext>[]
            {
                new HelpCommand(),
            };
        }
        
        internal override void OnInitialized()
        {
            if(!slientMode)
            {
                Write("Crispy Chess engine\n");
            }
        }

        internal override void OnCommandNotFound(string commandName)
        {
            Write($"Command not found: {commandName}\n");
        }
    }
}