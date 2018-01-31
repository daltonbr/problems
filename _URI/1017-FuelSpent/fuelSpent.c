/*
Fuel Spent

Little John wants to calculate and show the amount of spent fuel liters on a trip, using a car that does 12 Km/L.
For this, he would like you to help him through a simple program. To perform the calculation, you have to read 
spent time (in hours) and the same average speed (km/h). In this way, you can get distance and then, calculate
 how many liters would be needed. Show the value with three decimal places after the point.

Input

The input file contains two integers.
The first one is the spent time in the trip (in hours).
The second one is the average speed during the trip (in Km/h).

Output

Print how many liters would be needed to do this trip, with three digits after the decimal point.

Input Sample	Output Sample
10              70.833
85

2               15.333
92

22              122.833
67

Author: Dalton Lima github @daltonbr daltonvarussa@gmail.com
https://www.urionlinejudge.com.br/judge/en/problems/view/1017
*/

#include <stdio.h>

void main ()
{
	float spentTime;			 // in hours
	float averageSpeed;			 // in Km/h
    float consumption = 12.0;    // in Km/L
	float distance;				 // traveled distance in meters
	float fuelNeeded;

	//printf("Enter the TIME (h) spent in the trip: ");
	scanf("%f", &spentTime);

	//printf("Enter the AVERAGE SPEED (Km/h) of the trip: ");
	scanf("%f", &averageSpeed);

	distance = averageSpeed * spentTime;
	//printf("Distance traveled: %.3f \n", distance);

	fuelNeeded = distance / consumption;
	//printf("Fuel Needed: %.3f \n", fuelNeeded);
	printf("%.3f\n", fuelNeeded);

}