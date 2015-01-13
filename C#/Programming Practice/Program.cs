using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programming_Practice
{
    class Program
    {
        static void Main(string[] args)
        {
            GenericList<int> list = new GenericList<int>(5);
            list.Add(1);
            list.Add(3);
            list.Add(2);
            list.Print();
            list.Delete(1);
            Console.WriteLine("Just Deleted");
            list.Print();
            Console.WriteLine("Last Node: " + list.EndOfList().Data);
            Console.WriteLine("Count: " + list.Count());
            Console.WriteLine("Press enter to exit");
            Console.ReadLine();
        }
    }
}
