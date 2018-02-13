/* Sets - STL
https://www.hackerrank.com/challenges/cpp-sets/problem
*/

#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int q, queryType, queryElement;
    set<int> mySet;

    cin >> q;

    while (q--)
    {
        cin >> queryType >> queryElement;

        switch (queryType)
        {
            case (1): // Insert
            {
                mySet.insert(queryElement);                
                break;
            }
            case (2): // Erase
            {
                mySet.erase(queryElement);                
                break;
            }
            case (3): // Search
            {
                cout << (mySet.find(queryElement) == mySet.end() ? "No" : "Yes") << endl;
                
                /* or with an iterator
                set<int>::iterator it = mySet.find(queryElement);

                if ((it) != mySet.end())
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }                
                */
                break;
            }
        }
    }

    return 0;
}
