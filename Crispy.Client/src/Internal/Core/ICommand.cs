namespace Crispy.Client.Internal.Core
{
    internal interface ICommand<T> where T : ClientContext<T>
    {
        void Initialize(T context);
        void Execute(string[] args , T context);
    }
}