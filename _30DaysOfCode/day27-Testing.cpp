/*.
Day 27 Testing
https://www.hackerrank.com/domains/tutorials/30-days-of-code?filters%5Bstatus%5D%5B%5D=unsolved&badge_type=30-days-of-code
*/

#include <iostream>
#include <vector>
using namespace std;

void solution (int n, int k, vector<int> a)
{
    cout << n << " " << k << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int testCases = 5;
    
    cout << testCases << endl;

    solution(4, 3 , {-1, 0, 4, 2});
    solution(5, 2, {0, -1, 2, 1, 4});
    solution(7, 6, {2, 0, -1, 1 , 1 , 1, 1});
    solution(3, 1, {-1, 0, 4});
    solution(6, 4, {0, -1, 1, 4, 5, 6});
    
    return 0;
}
