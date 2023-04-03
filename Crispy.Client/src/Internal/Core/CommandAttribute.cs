using System;
namespace Crispy.Client.Internal.Core
{
    [AttributeUsage(AttributeTargets.Class, AllowMultiple = false)]
    internal class CommandAttribute : System.Attribute
    {
        public string CommandName {get; private set;}
        public string Description {get; private set;}
        public string HelpArgs {get; private set;}
        
        public CommandAttribute(string commandName, string description = "" , string helpArgs = "")
        {
            this.CommandName = commandName;
            this.Description = description;
            this.HelpArgs = helpArgs;
        }
    }
}