/*
Day 28 RegEx, Patterns, and Intro to Databases
https://www.hackerrank.com/challenges/30-regex-patterns/problem
*/

#include <cstdio>
#include <vector>
#include <iostream>
#include <regex>
#include <map>
using namespace std;

int main()
{
    int n; cin >> n;
    map<string, string> contact;
    vector<string> output;

    // reading all inputs
    for (int i = 0; i < n; i++)
    {
        string tempName, tempEmail;
        cin >> tempName >> tempEmail;
        contact.insert(pair <string, string> (tempEmail, tempName) );

    }

    // regex
    string gmail_mask = "[a-z]+@gmail.com";
    regex gmail_regex(gmail_mask);

    map<string, string>::iterator it;
    for (it = contact.begin(); it != contact.end(); ++it)
    {                
        if (regex_search(it->first, gmail_regex))
        {
            // match: this is a gmail
            // push the name in the output vector
            output.push_back(it->second);
        }       
    }

    sort(output.begin(), output.end());

    // output
    for (vector<string>::iterator it = output.begin(); it != output.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
