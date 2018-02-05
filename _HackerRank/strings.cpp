/*
https://www.hackerrank.com/challenges/c-tutorial-strings/problem
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string string1, string2;
    cin >> string1;
    cin >> string2;

    int len1 = string1.size();
    int len2 = string2.size();

    cout << len1 << " " << len2 << endl;
    cout << string1 + string2 << endl;

    // swaping the first character
    char temp = string1[0];
    string1[0] = string2[0];
    string2[0] = temp;

    cout << string1 << " " << string2 << endl;
  
    return 0;
}
