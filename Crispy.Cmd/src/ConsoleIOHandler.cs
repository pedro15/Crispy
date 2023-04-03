using System;

namespace Crispy.Cmd
{
    class ConsoleIOHandler : Crispy.Client.IClientIOHandler
    {
        public string GetInput()
        {
            return Console.ReadLine();
        }
        
        public void OnClientResponse(string message)
        {
            Console.Write(message);
        }
    }
}