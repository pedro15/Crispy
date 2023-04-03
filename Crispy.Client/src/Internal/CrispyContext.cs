using Crispy.Client.Internal.Core;
using Crispy.Client.Internal.Commands.Common;
using System.Reflection;

namespace Crispy.Client.Internal
{
    internal class CrispyContext : ClientContext<CrispyContext>
    {
        private const string AUTHORS = "Pedro Duran";
        private const string HOMEPAGE = "https://github.com/pedro15/Crispy";
        private static readonly string VERSION = Assembly.GetExecutingAssembly().GetName().Version.ToString(3);
        public bool slientMode = false;
        internal override ICommand<CrispyContext>[] GetCommands()
        {
            return new ICommand<CrispyContext>[]
            {
                new HelpCommand(),
                new QuitCommand(),
            };
        }

        internal override void OnInitialized()
        {
            if(!slientMode)
            {
                DisplayWelcomeMessage();
            }
        }

        internal override void OnCommandNotFound(string commandName)
        {
            Write($"Command not found: {commandName}\n");
        }

        private void DisplayWelcomeMessage()
        {
            System.Text.StringBuilder builder = new System.Text.StringBuilder();
            builder.Append(@"
             ______   ______   __   ______   ______  __  __    
            /\  ___\ /\  == \ /\ \ /\  ___\ /\  == \/\ \_\ \   
            \ \ \____\ \  __< \ \ \\ \___  \\ \  _-/\ \____ \  
             \ \_____\\ \_\ \_\\ \_\\/\_____\\ \_\   \/\_____\ 
              \/_____/ \/_/ /_/ \/_/ \/_____/ \/_/    \/_____/ 
                        C H E S S ---- E N G I N E");
            builder.AppendLine();
            builder.Append($"Version {VERSION}");
            builder.AppendLine();
            builder.Append($"Developed by {AUTHORS}");
            builder.AppendLine();
            builder.Append("Licensed under Mozzila Public License v2.0");
            builder.AppendLine();
            builder.Append($"Project Homepage and source code: {HOMEPAGE}");
            builder.AppendLine();
            builder.AppendLine();
            builder.AppendLine("execute 'help' to see all available commands");
            builder.AppendLine();
            
            Write(builder.ToString());
        }
    }
}