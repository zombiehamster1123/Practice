using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programming_Practice
{
     class GenericList<T> : IDataStructure
    {
        private Node<T> head = null;
        private int size = 0;

        public Node<T> Head
        {
            get { return this.head != null ? this.head : null; }
            set { this.head = value; }
        }

        public int Size
        {
            get { return this.size; }
            set { this.size = value; }
        }

        public GenericList() 
        {
            Reset();
        }

        public GenericList(T newData)
        {
            head = new Node<T>(newData);
            this.size = 1;
        }

        public GenericList(GenericList<T> aList)
        {
            this.Reset();
            for (int i = 0; i < aList.size; ++i)
                this.Add(aList[i].Data);
        }

        /// <summary>
        /// Get a particular node in the list
        /// </summary>
        /// <param name="index">Depth in the list</param>
        /// <returns>Node</returns>
        public Node<T> this[int index]
        {
            get
            {
                if (this.isValidIndex(index))
                {
                    Node<T> iterator = head;
                    for (int i = 0; i < index; ++i)
                        iterator = iterator.Next;

                    return iterator;
                }

                return null;
            }
        }

        /// <summary>
        /// Checks to see if index is within range
        /// of the size of the data structure
        /// </summary>
        /// <param name="index">The number to test with</param>
        /// <returns></returns>
        public bool isValidIndex(int index)
        {
            return 0 <= index && index < this.size;
        }

        public void Add(T newData)
        {
            this.EndOfList().Next = new Node<T>(newData);
            ++size;
        }

        public bool IsEmpty()
        {
            if (head == null)
                return true;

            return false;
        }

        /// <summary>
        /// Prints all data in the list
        /// </summary>
        public void Print()
        {
            Node<T> temp = head;
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
            // In case I ever decide to remove the
            // size member
            //int counter = 0;
            //Node<T> temp = head;
            //while (temp != null)
            //{
            //    temp = temp.Next;
            //    ++counter;
            //}

            //return counter;
            return this.size;
        }

        /// <summary>
        /// Get the last Node in the list
        /// </summary>
        /// <returns>A copy of the last node</returns>
        public Node<T> EndOfList()
        {
            if (this.size > 0)
            {
                Node<T> temp = this.head;
                while (temp.Next != null)
                    temp = temp.Next;

                return temp;
            }

            return null;
        }

        /// <summary>
        /// Delete a node within the list
        /// </summary>
        /// <param name="index">The position of the node</param>
        public void Delete(int index)
        {
            if (index <= 0)
                head = head.Next;
            else if (this.size < index)
                this[this.size - 2].Next = null;
            else
                this[index - 1].Next = this[index + 1];

            --size;
        }

        private void Reset()
        {
            this.head = null;
            this.size = 0;
        }
    }
}
