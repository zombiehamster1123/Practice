using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programming_Practice
{
    class Node<T>
    {
        private T data;
        private Node<T> next;

        public T Data { get { return this.data; } set { this.data = value; } }
        public Node<T> Next { get { return this.next; } set { this.next = value; } }

        public Node() { this.data = default(T); this.next = null; }
        public Node(T newData) { this.data = newData; this.next = null; }
        public Node(Node<T> other) { this.data = other.data; this.next = other.next; }
    }

    class GenericList<T>
    {
        private Node<T> head;

        public Node<T> Head
        {
            get { return head != null ? head : null; }
            set { head = value; }
        }

        public GenericList() 
        {
            Reset();
        }

        public GenericList(T newData)
        {
            head = new Node<T>(newData);
        }

        public void Add(T newData)
        {
            Node<T> temp = head;
            while (temp.Next != null)
                temp = temp.Next;

            temp.Next = new Node<T>(newData);
        }

        /// <summary>
        /// Prints all data in the list
        /// </summary>
        public void Print()
        {
            Node<T> temp = head;
            Console.Write("| ");
            while (temp != null)
            {
                Console.Write(temp.Data + " | ");
                temp = temp.Next;
            }
            Console.Write("\n");
        }

        /// <summary>
        /// Count the number of nodes in the list
        /// </summary>
        /// <returns></returns>
        public int Count()
        {
            int counter = 0;
            Node<T> temp = head;
            while (temp != null)
            {
                temp = temp.Next;
                ++counter;
            }

            return counter;
        }

        /// <summary>
        /// Get the last Node in the list
        /// </summary>
        /// <returns>A copy of the last node</returns>
        public Node<T> EndOfList()
        {
            Node<T> temp = head;
            while (temp.Next != null)
                temp = temp.Next;

            return temp;
        }

        /// <summary>
        /// Delete a node within the list
        /// </summary>
        /// <param name="index">The position of the node</param>
        public void Delete(int index)
        {
            // If first index or lower
            // remove the head node
            if (index <= 1)
                head = head.Next;
            else
            {
                // Check to make sure index is within 
                // the size of the list
                int currentSize = this.Count();
                if (index > currentSize)
                    index = currentSize;

                // Iterate to the node before the
                // node we want to delete
                Node<T> iterator = this.head;
                while (index > 2)
                {
                    iterator = iterator.Next;
                    --index;
                }
                
                // If within size replace the
                // node with the node after it
                // If deleting tail, set tail to null
                if (iterator.Next != null)
                    iterator.Next = iterator.Next.Next;
                else
                    iterator = null;                   
            }
        }

        private void Reset()
        {
            head = null;
        }
    }
}
