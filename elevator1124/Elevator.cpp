/*
	Elevator #1124
	Author: Dalton Lima github @daltonbr daltonvarussa@gmail.com
	https://www.urionlinejudge.com.br/judge/en/problems/view/1124

	As there is a very large amount of elevators and types of cylinders, FCC hired you to write 
	a program that, given the dimensions of the elevator and of the two cylinders, determines 
	whether it is possible to put the two cylinders in the elevator.

		Input

	The input contains several test cases. The first and only line of each test case contains 
	four integers L, C, R1 e R2,, separated by blanks, indicating the width (1 ≤ L ≤ 100) 
	nd the length (1 ≤ C ≤ 100) of the elevator and the radius of the cylinders (1 ≤ R1, R2 ≤ 100).

	The last test case is followed by a line containing four zeros separated by blanks.

		Output

	For each test case your program should print a single line with a single character,
	`S' if you can put the two cylinders in the elevator and `N' otherwise.

	Input Sample	Output Sample
	11 9 2 3		S
	7 8 3 2			N
	10 15 3 7		N
	8 9 3 2			S
	0 0 0 0

*/

#define _USE_MATH_DEFINES  //math constants
#include <iostream>
#include <math.h>
#include <xtgmath.h>


using namespace std;

//Diameter Circumference = PI * diameter
//Pytagorean Theorem 
//result = sqrt(a*a + b*b);

int main() 
{
	// (1 ≤ width ≤ 100)
	// (1 ≤ length ≤ 100)
	// radius of the cylinders (1 ≤ R1, R2 ≤ 100)
	int width, length, r1, r2;
	int d1, d2;						//caching diameters for the two cylinders
	int smallerSide, biggerSide;
	
	do
	{
		cin >> width;
		cin >> length;
		cin >> r1;
		cin >> r2;
		
		if (width == 0) return 0; // ONLY program ending condition!

		//auxiliary variables
		d1 = r1 * 2;
		d2 = r2 * 2;

		if (width < length)
		{
			smallerSide = width; biggerSide = length;
		}
		else
		{
			smallerSide = length; biggerSide = width;
		}

		//1st test - individual fiting
		if (d1 > smallerSide || d2 > smallerSide)
		{
			//failed
			cout << "N\n";
		}
		else
		{
			cout << "S\n";
		}

	} while (true);
	
	return 0;
}