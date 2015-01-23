using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programming_Practice
{
    class Stack<T> : GenericList<T>
    {
        public Stack()
        {
            this.Head = null;
        }

        public Stack(T newData)
        {
            this.Head = new Node<T>(newData);
        }

        public Stack(Stack<T> aStack)
        {
            for (int i = 0; i < aStack.Count(); ++i)
                this.Add(aStack[i].Data);
        }

        public T Pop()
        {
            if (this.Size > 0)
            {
                Node<T> holder = this.EndOfList();
                this[this.Size - 2].Next = null;

                return holder.Data;
            }

            return default(T);
        }

        public void Push(T newData)
        {
            if (this.Size > 0)
                this.EndOfList().Next = new Node<T>(newData);
            else
                this.Head = new Node<T>(newData);

            ++this.Size;
        }

        public T Peek()
        {
            if (this.Size > 0)
                return this.EndOfList().Data;

            return default(T);
        }
    }
}
