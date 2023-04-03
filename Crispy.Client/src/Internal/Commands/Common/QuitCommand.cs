using Crispy.Client.Internal.Core;

namespace Crispy.Client.Internal.Commands.Common
{
    [Command("quit" , "Stops program execution")]
    internal class QuitCommand : ICommand<CrispyContext>
    {
        public void Execute(string[] args, CrispyContext context)
        {
            context.Kill();
        }

        public void Initialize(CrispyContext context)
        {
            
        }
    }
}