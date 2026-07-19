using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloWorld
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int i = 1000;
            while (i < 2000)
            {
                Console.WriteLine(i);
                i++;
            }
            Console.ReadLine();

        }
    }
}
