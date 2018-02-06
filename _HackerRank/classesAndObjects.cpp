/*
Classes And Objects
https://www.hackerrank.com/challenges/classes-objects/problem
*/

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Student
{
    public:
        static const int NumberOfExams = 5;
        void input()
        {
            for(int i = 0; i < NumberOfExams; i++)
            {
                cin >> scores[i];
            }
        }

        // sum of the student's scores
        int calculateTotalScore()
        {
            int totalScore = 0;
            for(int i = 0; i < NumberOfExams; i++)
            {
                totalScore += scores[i];
            }
            return totalScore;
        }
        
    private:
        // hold 5 exam scores
        int scores[NumberOfExams];
};

// This code bellow is supplied and LOCKED

    int main()
    {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
