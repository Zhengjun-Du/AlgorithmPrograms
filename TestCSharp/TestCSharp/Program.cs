using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Linq.Expressions;

namespace TestCSharp
{
    class Product
    {
        
        public int ID;
        public int price;

       public Product(int i, int p)
        {
            ID = i;
            price = p;
        }
    }

    class Program
    {
        static List<Product> products = new List<Product>(5);

        static void Main(string[] args)
        {
            string s = ",1,2,3";
            string[] ss=s.Split(new char[]{','},StringSplitOptions.RemoveEmptyEntries);
            
           
            products.Add(new Product(1, 5));
            products.Add(new Product(1, 2));
            products.Add(new Product(3, 8));
            products.Add(new Product(6, 4));
            products.Add(new Product(2, 1));

            var x = from p in products
                    where p.ID > 2
                    orderby p.ID
                    select new { x = p.ID, y = p.price, z = 1};

            Console.WriteLine("1. LINQ 语句查询结果：");
            foreach (var v in x)
            {
                Console.WriteLine(v.x +", "+ v.y);
            }


            Console.WriteLine("2. LINQ 函数句查询结果：");
            
            //IEnumerable<Product> y = products.Where(p => p.price > 3 && p.ID < 5);
            IEnumerable<Product> y = Get(p => p.price > 1).OrderBy(c => c.price);
            foreach (var v in y)
            {
                Console.WriteLine(v.ID + ", " + v.price);
            }
            

         

        }

        public static IEnumerable<Product> Get(Func<Product, bool> filter)
        {
            return products.Where(filter).AsQueryable();
        }

    }
}
