using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Class: AdvertisingAgency
//Method: numberOfRejections
//Parameters: int[]
//Returns: int
//Method signature: int numberOfRejections(int[] requests)
//(be sure your method is public)

namespace AdvertisingAgency_cs
{
    public class AdvertisingAgency
    {
        public int numberOfRejections(int[] requests)
        {
            int rejections = 0, size = 100;
            bool[] banners = new bool[size];
                        
            for (int i = 0; i < requests.Length; i++ )
            {
                if (!banners[requests[i]-1])
                {
                    banners[requests[i]-1] = true;
                } else
                {
                    rejections++;
                }
                
            }
            return rejections;
        }
        static void Main(string[] args)
        {
            AdvertisingAgency aa = new AdvertisingAgency();
            
            int[] requests = new int[7] { 1, 2, 3, 4, 5, 1, 3 };

            Console.WriteLine(aa.numberOfRejections(requests));
            
            // Keep the console window open in debug mode.
            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
            
        }
    }
}

