/*
https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem
*/

#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n; cin >> n;
    std::unordered_map<string, string> phoneBook;

    // reading entries
    std::string name, phone;
    for (int i = n-1; i >= 0; i--)
    {        
       cin >> name;       
       getchar(); // blank space
       cin >> phone;
       phoneBook[name] = phone;
    }

    // Iterate and print keys and values of unordered_map
    // for( const auto& n : phoneBook ) {
    //     std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    // }
    
    string queryInput;
    // queries
    while(cin >> queryInput)
    {
        auto search = phoneBook.find(queryInput);
        if (search != phoneBook.end())
        {
            cout << search->first << "=" << search->second << endl;
        }
        else
        {
            cout << "Not found" << endl;
        }
    }
    return 0;
}
