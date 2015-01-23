using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programming_Practice
{
    class Program
    {
        static void TestList()
        {
            GenericList<int> list = new GenericList<int>(5);
            list.Add(1);
            list.Add(3);
            list.Add(2);
            list.Print();
            list.Delete(5);
            Console.WriteLine("Just Deleted 2:");
            list.Print();
            Console.WriteLine("Last Node: " + list.EndOfList().Data);
            Console.WriteLine("Count: " + list.Count());
            Console.WriteLine("IsEmpty: " + list.IsEmpty());
            GenericList<int> list2 = new GenericList<int>();
            Console.WriteLine("IsEmpty2: " + list2.IsEmpty());
            list = list2;
            Console.WriteLine("IsEmpty: " + list.IsEmpty());
            list.Print();
        }

        static void TestStack()
        {
            Stack<int> s1 = new Stack<int>();
            s1.Print();
            s1.Push(2);
            s1.Push(5);
            s1.Print();
            Console.WriteLine("Pop goes the stack: " + s1.Pop());
            s1.Print();
            Stack<int> s2 = new Stack<int>(99);
            s2.Print();
            s1 = s2;
            s1.Print();
            s2.Print();
            Console.WriteLine(s1.Peek());
        }

        static void TestHashTable()
        {
            HashTable<int, string> ht1 = new HashTable<int, string>();
            Console.WriteLine("HashTable1: ");
            ht1.Print();
            HashTable<int, string> ht2 = new HashTable<int, string>(1, "Hello");
            Console.WriteLine("HashTable2: ");
            ht2.Print();
            ht2.Add(2, "World");
            ht2.Add(1, "Bloop");
            ht2.Add(3, "Moot");
            Console.WriteLine("HashTable2: ");
            ht2.Print();
            ht1 = ht2;
            Console.WriteLine("HashTable1: ");
            ht1.Print();
            ht1.Find(1);
        }

        static void TestAlgorithms()
        {
            int[] numbers = new int[] {3, 4, 5, 1, 2};
            Algorithms a1 = new Algorithms();
            Console.WriteLine("Searched returned: " + a1.search(numbers, 0, 4, 2));
        }

        static void TestPatterns()
        {
            //AbstractFactory factory = new AbstractFactory();
            //factory.MainApp();

            //Builder builder = new Builder();
            //builder.MainApp();

            //FactoryMethod factoryMethod = new FactoryMethod();
            //factoryMethod.MainApp();

            //Prototype prototype = new Prototype();
            //prototype.MainApp();

            //Singleton singleton = new Singleton();
            //singleton.MainApp();

            //Adapter adapter = new Adapter();
            //adapter.MainApp();

            //Bridge bridge = new Bridge();
            //bridge.MainApp();

            //Composite composite = new Composite();
            //composite.MainApp();

            //DecoratorPattern decorator = new DecoratorPattern();
            //decorator.MainApp();

            //Facade facade = new Facade();
            //facade.MainApp();

            //Flyweight flyweight = new Flyweight();
            //flyweight.MainApp();

            //Proxy proxy = new Proxy();
            //proxy.MainApp();

            //ChainOfResponsibility chain = new ChainOfResponsibility();
            //chain.MainApp();

            CommandPattern command = new CommandPattern();
            command.MainApp();
        }

        static void Main(string[] args)
        {
            //TestList();
            //TestStack();
            //TestHashTable();
            //TestAlgorithms();
            //TestPatterns();

            List<string> list;
            Dictionary<string, List<string>> anagrams = new Dictionary<string, List<string>>();
            list = new List<string>();
            list.Add("aba");
            anagrams.Add("aab", list);
            anagrams["aab"].Add("baa");
            //anagrams.Add("aac", "caa");
            //anagrams["aab"].Contains("aba");
            //anagrams.Add("aac", "aca");
            foreach (List<string> l in anagrams.Values)
                foreach(string s in l)
                    Console.WriteLine("Value = {0}", s);

            Console.WriteLine("Press enter to exit");
            Console.ReadLine();
        }
    }
}
