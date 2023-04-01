using System;
using Crispy.Client;

namespace Crispy.Cmd
{
    public static class Program 
    {
        public static int Main(string[] args)
        {
            Console.WriteLine("Hello, world!");
            Console.WriteLine(typeof(CrispyClient).AssemblyQualifiedName);
            Console.Read();
            return 0;
        }
    }
}