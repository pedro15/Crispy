using Crispy.Client.Internal;

namespace Crispy.Client
{
    public sealed class EngineClient
    {
        public bool IsRunning => crispyContext.IsRunning;
        private CrispyContext crispyContext = null;
        
        public EngineClient(IClientIOHandler iOHandler,string[] args)
        {
            crispyContext = new CrispyContext();
            crispyContext.Initialize(iOHandler);
        }
        
        public void Run(bool runInBackgroundThread = false)
        {
            crispyContext.Run(runInBackgroundThread);
        }

        public void StopEngine()
        {
            if (crispyContext.IsRunning)
            {
                crispyContext.Kill();
            }
        }
    }
}