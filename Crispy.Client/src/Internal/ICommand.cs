namespace Crispy.Client.Internal
{
    internal interface ICommand<T> where T : ContextBase<T>
    {
        void Initialize();
        void Execute(T context, string[] tokens);
    }
}