/*
	Musical Loop
	Author: Dalton Lima github @daltonbr daltonvarussa@gmail.com
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
#include <string>
using namespace std;

void main()
{
	int numberSample, peakCount = 1;

	int firstSample, sample, lookAheadSample;
	bool changeDirection, goingUp, goingUpAgain;

	cin >> numberSample;

	while (numberSample != 0)
	{
		//trivial case, just 1 sample
		while (numberSample == 1)
		{
			cin >> sample; //just reading the unique sample
			peakCount = 1;
			cout << peakCount << "\n";
			cin >> numberSample; //reading the next numberSample
			if (numberSample != 0) {return;}
		}

		//at this point, we have at least 2 or more samples
		
		//save the first sample to compare later with the last one
		cin >> firstSample >> sample;

		for (int i = 1; i < numberSample; i++)
		{
			cin >> lookAheadSample;
				
			goingUp = lookAheadSample > sample;

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
			i++;

			goingUpAgain = lookAheadSample > sample;

			// if the last two directions diverge, we have a peak
			if (goingUp != goingUpAgain) {peakCount++;}

		}
		cout << peakCount << "\n";
		cin >> numberSample;
	}
	return;
}
//amor
//d