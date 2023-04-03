using System.Text;
using Crispy.Client.Internal.Core;
namespace Crispy.Client.Internal.Commands.Common
{
    [Command("help" , "Displays CommandLine help")]
    internal class HelpCommand : ICommand<CrispyContext>
    {
        public void Initialize(CrispyContext context)
        {
            
        }

        public void Execute(string[] args, CrispyContext context)
        {
            StringBuilder builder = new StringBuilder();
            builder.AppendLine();

            CommandAttribute[] info = context.GetCommandsInfo();

            for (int i = 0; i < info.Length; i++)
            {
                CommandAttribute curr = info[i];
                builder.AppendFormat("{0,-12}{1,10}{2,30}\n" , curr.CommandName, curr.Description, curr.HelpArgs);
            }

            builder.AppendLine();
            context.Write(builder.ToString());
        }
    }
}