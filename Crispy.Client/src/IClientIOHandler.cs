namespace Crispy.Client
{
    public interface IClientIOHandler
    {
        void OnClientResponse(string message);
        string GetInput();
    }
}