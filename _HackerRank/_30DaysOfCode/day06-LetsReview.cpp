/* Day 4 - Let's Review
https://www.hackerrank.com/challenges/30-review-loop/problem
*/

#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> stringVector;
    
    for (int i = 0; i < n; i++)
    {
        string currentLine;
        cin >> currentLine;
        stringVector.push_back(currentLine);
    }

    for (int i = 0; i < n; i++)
    {
        string currentLine = stringVector[i];
        string oddChars;
        for (int j = 0; j < currentLine.length(); j++)
        {
            if (j % 2 == 0)
            {
                cout << currentLine[j];
            }
            else
            {
                oddChars.push_back(currentLine[j]);
            }
        }
        cout << " " << oddChars << endl;
    }

    return 0;
}
