using System.Collections.Generic;

namespace Crispy.Client.Internal
{
    internal sealed class CrispyContext : ContextBase<CrispyContext>
    {
        internal override ICommand<CrispyContext>[] GetCommands()
        {
            return new ICommand<CrispyContext>[] 
            {
                
            };
        }
    }
}