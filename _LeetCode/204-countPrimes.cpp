/*
204. Count Primes
https://leetcode.com/problems/count-primes/description/

Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/


// not so good solution O(n^2) - TLE - Time Limit Exceeded
class Solution {
public:
    int countPrimes(int n) {
        int primeCount = 2;        
        
        if (n == 2) return 0;
        if (n == 3) return 1;
        
        for (int test = 4; test < n; ++test) {
            bool isPrime = true;
            for (int count = 2; count < test; ++count ) {
                if (test % count == 0) {
                    isPrime = false;
                    break;
                }               
            }
            if (isPrime) primeCount++;
        }
        
        return primeCount;
    }
};

// better solution
class Solution {
public:
    int countPrimes(int n) {
        int primeCount = 2;        
        bool isPrime;
        
        if (n <= 2) return 0;        
        if (n == 3) return 1;
        if (n == 4) return 2;
        
        for (int test = 5; test < n; test += 2) {            
             isPrime = true;            
           
            int cacheSqrt = sqrt(test);
            for (int current = 3; current < test && current <= cacheSqrt; current += 2 ) {                
                if (test % current == 0) {
                    isPrime = false;
                    break;
                }               
            }
            if (isPrime) primeCount++;
        }
        
        return primeCount;
    }
};