
/* - Maps - STL
https://www.hackerrank.com/challenges/cpp-maps/problem
*/

#include <iostream>
#include <algorithm>
#include <map>  // this is a ordered map
// we also could use #include <unordered_map> too
using namespace std;

int main()
{
    std::map<string, int> myMap;

    int q, queryType;
    cin >> q;

    while (q--)
    {
        string inputName;
        int inputInt;
        cin >> queryType;

        switch (queryType)
        {
            case 1: // insert new or add to existing entries
            {
                cin >> inputName >> inputInt;
                auto it = myMap.find(inputName);
                if (it == myMap.end())
                {
                    // adding new
                    myMap.insert( std::pair<string, int>(inputName, inputInt) );
                }
                else
                {
                    // adding to existing ones
                    it->second += inputInt;
                }
                break;
            }
            case 2: // erase
            {
                cin >> inputName;
                myMap.erase(inputName);
                break;
            }
            case 3: // search
            {
                cin >> inputName;
                map<string, int>::iterator it = myMap.find(inputName);
                if (it == myMap.end())
                {
                    // Student not found! - default to zero
                    cout << "0" << endl;
                }
                else
                {
                    // print existing values
                    cout << it->second << endl;
                }
                break;
            }
        }
    }

    return 0;
}
