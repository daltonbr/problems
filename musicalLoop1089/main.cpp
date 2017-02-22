/*
  main.cpp
  musicalLoop #1089

  Created by Dalton Varussa De Oliveira Lima on 22/02/17.
  github @daltonbr daltonvarussa@gmail.com
  https://www.urionlinejudge.com.br/judge/en/problems/view/1089
 
 Input
 
 The input contains several test cases. The first line of a test case contains one integer N, representing the number
 of samples in the musical loop composed by Fernanda (2 ≤ N ≤ 104). The second line contains N integers Hi, separated
 by spaces, representing the sequence of magnitudes sampled (-104 ≤ Hi ≤ 104 for 1 ≤ i ≤ N, H1 ≠ HN and Hi ≠ Hi+1 for 1 ≤ i < N).
 Notice that H1 follows HN when the loop is played.
 
 The end of the input is indicated by a line that contains only one zero.
 
 Output
 
 For each test case in the input your program must print a single line, containing one integer, the number of peaks that
 exist in the musical loop.
 
 Input Sample				Output Sample
 2							2
 1 -3						2
 6							4
 40 0 -41 0 41 42
 4
 300 450 449 450
 0
 
 */

#include <iostream>
//#include <string>
using namespace std;

int main(int argc, const char * argv[])
{
    //freopen("input.dat", "r", stdin); // redirects standard input
    //freopen("output.dat", "w", stdout); // redirects standard output
    
    if(freopen("input.dat", "r", stdin))
    {
        cout << "input.dat open to read data\n";
    }
    else
    {
        cout << "ERROR: input.dat can't be opened or unexist!\n";
        return -1;
    }
    
    int numberSample, peakCount = 1;
    
    int firstSample, secondSample, sample, lookAheadSample;
    bool goingUp, goingUpAgain;
    
    cin >> numberSample;
    
    while (numberSample != 0)
    {
        peakCount = 0;
        //cout << "\n";
        
        //trivial case, just 1 sample
        while (numberSample == 1)
        {
            cin >> sample; //just reading the unique sample
            peakCount = 1;
            cout << /*"peaks: " << */peakCount;
            cin >> numberSample; //reading the next numberSample
            peakCount = 0;
            if (numberSample == 0) {return 0;}
            cout << "\n";
        }
        
        //at this point, we have at least 2 or more samples
        
        //save the first and the second sample to compare later with the last one
        cin >> sample;
        firstSample = sample;
        
        cin >> lookAheadSample;
        secondSample = lookAheadSample;
        
        goingUp = lookAheadSample > sample;
        
        
        for (int i = 1; i < numberSample; i++)
        {
            
            //move to the next pair of samples
            sample = lookAheadSample;
            
            if (i == numberSample-1)  //we are on the next-to-last sample
            {
                lookAheadSample = firstSample;
            }
            else 
            {
                cin >> lookAheadSample;
            }
            
            goingUpAgain = lookAheadSample > sample;
            
            // if the last two directions diverge, we have a peak
            if (goingUp != goingUpAgain) {peakCount++;}
            goingUp = goingUpAgain;
        }
        
        //move to the next pair of samples
        sample = lookAheadSample;
        lookAheadSample = secondSample;
        
        goingUpAgain = lookAheadSample > sample;
        
        // if the last two directions diverge, we have a peak
        if (goingUp != goingUpAgain) {peakCount++;}
        
        cout << /*"peaks: " << */peakCount;
        cin >> numberSample;
    }
    return 0;
}
