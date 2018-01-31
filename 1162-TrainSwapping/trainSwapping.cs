/*
# Throwing Cards Away #1162
# Dalton Lima 01/23/18
https://www.urionlinejudge.com.br/judge/en/problems/view/1162

Train Swapping
Unknown Author

Timelimit: 1
At an old railway station, you may still encounter one of the last remaining “train swappers”.
A train swapper is an employee of the railroad, whose sole job it is to rearrange the carriages of trains.
Once the carriages are arranged in the optimal order, all the train driver has to do, is drop
 the carriages off, one by one, at the stations for which the load is meant.
The title “train swapper'' stems from the first person who performed this task, at a station
 close to a railway bridge. Instead of opening up vertically, the bridge rotated around a 
 pillar in the center of the river. After rotating the bridge 90 degrees, boats could pass
  left or right.
The first train swapper had discovered that the bridge could be operated with at most two 
carriages on it. By rotating the bridge 180 degrees, the carriages switched place, allowing him
 to rearrange the carriages (as a side effect, the carriages then faced the opposite direction,
 but train carriages can move either way, so who cares).
Now that almost all train swappers have died out, the railway company would like to automate
 their operation. Part of the program to be developed, is a routine which decides for a given
 train the least number of swaps of two adjacent carriages necessary to order the train.
 Your assignment is to create that routine.

Input
The input contains on the first line the number of test cases (N). Each test case consists of two input lines.
The first line of a test case contains an integer L, determining the length of the train (0 ≤ L ≤ 50).
The second line of a test case contains a permutation of the numbers 1 through L, indicating the current
order of the carriages. The carriages should be ordered such that carriage 1 comes first, then 2, etc.
with carriage L coming last.

Output
For each test case output the sentence: 'Optimal train swapping takes S swaps.' where S is an integer.

Input Sample
3
3
1 3 2
4
4 3 2 1
2
2 1

Output Sample
Optimal train swapping takes 1 swaps.
Optimal train swapping takes 6 swaps.
Optimal train swapping takes 1 swaps.

*/

using System;
namespace trainSwapping
{
    class trainSwapping
    {
        static void Main()
        {
            int testCases;
            string input;
            int swaps = 0;

            do
            {
                input = Console.ReadLine();
                testCases = Int32.Parse(input);
               
                for (int i = 0; i < testCases; i++)
                {
                    int carriageSize = Int32.Parse(input);

                    string carriage = Console.ReadLine();
                    Console.WriteLine("line input: " + carriage);

                    Console.WriteLine("TestCase number "+ i.ToString());
                }
                
            } while (input != null || testCases != 0);

            
            Console.WriteLine("Optimal train swapping takes " + swaps + " swaps.");

            // Keep the console window open in debug mode.
            Console.WriteLine("Press any key to exit.");          
            Console.ReadKey();
        }
    }
}