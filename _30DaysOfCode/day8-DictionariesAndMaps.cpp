/*
https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n; cin >> n;
    std::unordered_map<string, string> phoneBook =
    {
        {"Dalton","234-5678"},
        {"Carmack","555-5555"}
    };

    // reading entries
    // string name, phone;
    // for (int i = 0; i < n-1; i++)
    // {
    //     cin >> name >> phone;
    //     phoneBook.insert(name, phone);        
    // }

    // Iterate and print keys and values of unordered_map
    for( const auto& n : phoneBook ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
 
    // Add two new entries to the unordered_map
    phoneBook["BLACK"] = "#000000";
    phoneBook["WHITE"] = "#FFFFFF";
 
    // Output values by key
    std::cout << "The HEX of color RED is:[" << phoneBook["RED"] << "]\n";
    std::cout << "The HEX of color BLACK is:[" << phoneBook["BLACK"] << "]\n";

    // printing again
    for( const auto& n : phoneBook ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }

    return 0;
}
