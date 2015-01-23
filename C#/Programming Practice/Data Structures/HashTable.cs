using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programming_Practice
{
    class HashTable<KeyType, DataType> : IDataStructure
    {
        private Hash<KeyType, DataType>[] head;

        public HashTable()
        {
            Create();
        }

        public HashTable(KeyType aKey)
        {
            Create();
            this.head[0] = new Hash<KeyType, DataType>(aKey);
        }

        public HashTable(KeyType aKey, DataType newData)
        {
            Create();
            this.head[0] = new Hash<KeyType, DataType>(aKey, newData);
        }

        public HashTable(HashTable<KeyType, DataType> aHashTable)
        {
            this.head = aHashTable.head;
        }

        public void Add(KeyType aKey, DataType newData)
        {
            bool placed = false;
            int holder = GlobalVar.HashLength + 1;
            for (int i = 0; i < GlobalVar.HashLength; ++i)
            {
                if (this.IsKey(i, aKey))
                {
                    this.head[i].Elements.Add(newData);
                    placed = true;
                    break;
                }
                else if (this.head[i] == null && i < holder)
                    holder = i;
            }

            if (!placed)
                this.head[holder] = new Hash<KeyType, DataType>(aKey, newData);
        }

        private void Create()
        {
            head = new Hash<KeyType, DataType>[GlobalVar.HashLength];
        }

        public bool IsEmpty()
        {
            return this.head == null;
        }

        public int Count()
        {
            int count = 0;

            for (int i = 0; i < GlobalVar.HashLength; ++i)
                if (head[i] != null)
                    count += this.head[i].Elements.Size;

            return count;
        }

        public void Print()
        {
            for (int i = 0; i < GlobalVar.HashLength; ++i)
                if (this.head[i] != null)
                    this.head[i].Elements.Print();
        }

        private bool IsKey(int index, KeyType aKey)
        {
            return this.head[index] != null &&
                    IEquatable<KeyType>.Equals(this.head[index].Key, aKey);
        }

        public GenericList<DataType> Find(KeyType aKey)
        {
            for (int i = 0; i < GlobalVar.HashLength; ++i)
                if (this.IsKey(i, aKey))
                    this.head[i].Elements.Print();

            return null;
        }
    }
}
