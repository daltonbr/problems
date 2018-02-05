/*
Main concept bidimensional vectors
https://www.hackerrank.com/challenges/variable-sized-arrays/problem
*/

#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

struct query
{
    int i;
    int j;
}; typedef struct query query;

vector<int> parseInts(string str)
{  
    vector<int> output;
    stringstream ss(str);
    
    do
    {
        int tempInt;
        ss >> tempInt;
        output.push_back(tempInt);
    } while (!ss.eof());
    
    return output;
}

int main() {
    int n, queriesAmount;
    int i, j;
    string firstLineInput;
    getline(cin, firstLineInput);
    
    // Read and Parse the first line (n and q)
    vector<int> parsedFirstLine = parseInts(firstLineInput);
    n = parsedFirstLine[0];
    queriesAmount = parsedFirstLine[1];
    
    vector< vector<int> > inputs;
    vector<query> queries;

    for (int counter = 0; counter < n; counter++)
    {
        // get only the first char (size of the vector)
        int vectorSize;
        cin >> vectorSize;

        // read the rest of the entire line (unparsed)
        string tempInput;
        getline(cin, tempInput);

        // parse the int's to a vector
        vector<int> inputParsed = parseInts(tempInput);

        // push the vector into another vector (a bidimensional one)
        inputs.push_back(inputParsed);
    }

    
    for (int counter = 0; counter < queriesAmount; counter++)
    {
        // reading and parsing the queries
        string tempQueryString;
        getline(cin, tempQueryString);
        vector<int> tempVector = parseInts(tempQueryString);
        
        // putting inside of a query struct, and in another vector
        query tempQuery;
        tempQuery.i = tempVector[0];
        tempQuery.j = tempVector[1];
        queries.push_back(tempQuery);
    }

    // output
    for (int counter = 0; counter < queriesAmount; counter++)
    {
        int tempI, tempJ;
        tempI = queries[counter].i;
        tempJ = queries[counter].j;

        cout << inputs[tempI][tempJ] << endl;
    }

    return 0;
}
