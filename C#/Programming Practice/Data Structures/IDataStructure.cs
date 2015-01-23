using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programming_Practice
{
    public static class GlobalVar
    {
        public const int HashLength = 10;
    }

    class Node<T>
    {
        private T data = default(T);
        private Node<T> next = null;

        public T Data { get { return this.data; } set { this.data = value; } }
        public Node<T> Next { get { return this.next; } set { this.next = value; } }

        public Node() { this.data = default(T); this.next = null; }
        public Node(T newData) { this.data = newData; this.next = null; }
        public Node(Node<T> other) { this.data = other.data; this.next = other.next; }
    }

    class Hash<KeyType, DataType>
    {
        private KeyType key = default(KeyType);
        private GenericList<DataType> elements = null;

        public KeyType Key { get { return this.key; } set { this.key = value; } }
        public GenericList<DataType> Elements { get { return this.elements; } set { this.elements = value; } }

        public Hash() { this.key = default(KeyType); this.elements = null; }
        public Hash(KeyType aKey) { this.key = aKey; this.elements = null; }
        public Hash(KeyType aKey, DataType newData) { this.key = aKey; this.elements = new GenericList<DataType>(newData); }
        public Hash(Hash<KeyType, DataType> aHash) { this.key = aHash.key; this.elements = aHash.elements; }
    }

    interface IDataStructure
    {
        bool IsEmpty();
        int Count();
        void Print();
    }
}
