/*
	Musical Loop
	Author: Dalton Lima github @daltonbr daltonvarussa@gmail.com
	https://www.urionlinejudge.com.br/judge/en/problems/view/1089

*/

#include <iostream>
#include <string>
using namespace std;

void main()
{
	int numberSample;

	cin >> numberSample;
	
	while (numberSample != 0)
	{
		cout << "Number of Samples: " << numberSample << "\n";
		
		for (int i = 0; i > numberSample-1; i++)
		{
			cout << i << "\n";
		}
		
		cin >> numberSample;
	}
	
	return;
}