using System;
using Crispy.Client;
using System.Threading.Tasks;

namespace Crispy.Cmd
{
    public static class Program 
    {
        static int Main(string[] args)
        {
            Task mainTask = MainAsync(args);
            mainTask.Wait();

            return 0;
        }

        static async Task MainAsync(string[] args)
        {
            EngineClient client = new EngineClient(new ConsoleIOHandler() , args);
            client.Run(true);

            while(client.IsRunning)
            {
                await Task.Delay(1);
            }
        }


    }
}