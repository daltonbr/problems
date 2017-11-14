/*
	Even and Odd
	Author: Dalton Lima github @daltonbr daltonvarussa@gmail.com
	https://www.urionlinejudge.com.br/judge/en/problems/view/1259

Considering the input of non-negative integer values​​, sort these numbers ​​
according to the following criteria: First the even in ascending order 
followed by the odd in descending order.

Input

The first line of input contains a positive integer number N (1 < N < 105).
This is the number of following input lines.
The next N lines contain, each one, a integer non-negative number.

Output

Print all numbers according to the explanation presented above.
Each number must be printed in one line as shown below.

Sample Input	Sample Output
10              4
4               32
32              34
34              98
543             654
3456            3456
654             6789
567             567
87              543
6789            87
98

*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

int numberInputs;
int currentNumber;
std::list<int> odds;
std::list<int> evens;
std::list<int>::iterator it;

int main()
{
    
    std::cin >> numberInputs;

    for (int i = 0; i < numberInputs; i++)
    {        
        std::cin >> currentNumber;
        
        if (currentNumber % 2 == 0)
        {
            // Evens list
            it = std::lower_bound(evens.begin(), evens.end(), currentNumber);
            evens.insert(it, currentNumber);
        }
        else
        {
            // Odds list
            it = std::lower_bound(odds.begin(), odds.end(), currentNumber);
            odds.insert(it, currentNumber);
        }
    }

    // Evens Ascending
    for (it=evens.begin(); it!=evens.end(); ++it)
      std::cout << *it << std::endl;
    
    // Odds Descending
    std::list<int>::reverse_iterator rit;
    for (rit=odds.rbegin()--; rit!=odds.rend(); ++rit)
      std::cout << *rit << std::endl;;

}
