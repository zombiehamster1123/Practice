using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programming_Practice
{
    class Node
    {
        private int data = 0;
        private Node next = null;

        public int Data { get { return data; } set { data = value; } }
        public Node Next { get { return next; } set { next = value; } }

        public Node() { data = 0; next = null; }
        public Node(int newData) { data = newData; next = null; }
    }

    class RyanList
    {
        private Node head;

        public Node Head
        {
            get { return head != null ? head : null; }
            set { head = value; }
        }

        /*public Node GetHead() { return head; }
        public void SetHead(int newData) { head = new Node(newData); }
        public void SetHead(Node newNode) { head = newNode; }//*/

        public RyanList() 
        {
            Reset();
        }

        public RyanList(int newData)
        {
            head = new Node(newData);
        }

        public void Add(int newData)
        {
            Node temp = head;
            while (temp.Next != null)
                temp = temp.Next;

            temp.Next = new Node(newData);
        }

        public void Print()
        {
            Node temp = head;
            while (temp != null)
            {
                Console.WriteLine(temp.Data);
                temp = temp.Next;
            }
        }

        public int Count()
        {
            int counter = 0;
            Node temp = head;
            while (temp != null)
            {
                temp = temp.Next;
                ++counter;
            }

            return counter;
        }

        public Node EndOfList()
        {
            Node temp = head;
            while (temp.Next != null)
                temp = temp.Next;

            return temp;
        }

        private void Reset()
        {
            head = null;
        }
    }
}
