/*
Interfaces
https://www.hackerrank.com/challenges/30-interfaces/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
// supplied class
class AdvancedArithmetic{
    public:
        virtual int divisorSum(int n)=0;
};

//Write your code here
class Calculator : public AdvancedArithmetic
{
    public:
        int divisorSum(int n)
        {
            int sum = 0;
            for (int i = n; i > 0 ; i--)
            {
                if (n % i == 0) { sum += i; }
            }
            return sum;
        }
};

// supplied code stub

int main(){
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator(); 
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;
    return 0;
}