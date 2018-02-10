/* Acid Naming
https://www.hackerrank.com/contests/w36/challenges/acid-naming

If the given input starts with "hydro" and ends with "ic" then it is a non-metal acid.
If the input only ends with "ic" then it is a polyatomic acid.
If it does not have either case, then output not an acid.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n; cin >> n;

    while (n--)
    {
        string entry;
        cin >> entry;
        
        int size = entry.size();

        if (entry.compare(size-2,2,"ic") == 0 || size < 2)
        {
            // ends with "ic"
            if (entry.compare(0,5,"hydro") == 0)
            {
                cout << "non-metal acid" << endl;
            }
            else
            {
                cout << "polyatomic acid" << endl;
            }
        }
        else
        {
            cout << "not an acid" << endl;
        }
    }

    return 0;
}
