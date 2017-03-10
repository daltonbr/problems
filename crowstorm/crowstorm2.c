/*

    Problem: CrowStorm #2203
    Author: Dalton Lima github @daltonbr daltonvarussa@gmail.com
    https://www.urionlinejudge.com.br/judge/en/problems/view/2203

Fiddlesticks is a champion of League of Legends, he has as his ultimate ability
 "CrowStorm", it works as follows:

First Fiddlesticks chooses a strategic location and promptly he prepares to
resurface in one direction within a certain distance, then it is rooted and
channels the ultimate by just 1.5 seconds, after that time it resurfaces 
immediately at the target site with a flock of crows flying in the around and
causing much damage.

Fiddlesticks want your help to find out if in a certain position it is possible
 to achieve an invader with his ultimate skill.

Note: Consider that Fiddlesticks always uses his ultimate exactly in the
 direction of invasor and the invader always tries to flee in the opposite 
 direction to Fiddlesticks, at a constant speed.

    ##Input

The entry consists of several lines, each line contains the following integer
values: Xf, Yf, Xi, Yi, Vi, R1 and R2(0 ≤ Xf, Yf, Xi, Yi, Vi, R1 e R2 ≤ 100),
representing respectively the coordinates of Fiddlesticks, the initial
coordinates of the invader, the speed of the invader, the ultimate of
casting radius and flight radius of crows. Consider the unit of
measurement as the meter.

    ##Output

In the output you should print for each line the 'Y' character if it is
 possible to achieve the invasor or 'N' otherwise, both followed by a line break.

Input Sample            	Output Sample
4 6 22 6 0 16 2             Y
4 6 22 6 1 16 2             N
      
*/

#include <stdio.h>
#include <math.h>           // sqrt()

// auxiliary function declaration
// float magnitude(float x, float y);

typedef struct Vector2
{
    float x;
    float y;
} Vector2;

Vector2 sum(Vector2 firstVector, Vector2 secondVector);
Vector2 multiplicationByScalar(Vector2 vector, float scalar);
Vector2 inverse(Vector2 vector);
void printVector(Vector2 vector);
float magnitude(Vector2 vector);
Vector2 normalized(Vector2 vector);

int main ()
{

    const float castTime = 1.5f;
    Vector2 heroPosition;           // (Xf, Yf)
    float Vi;                        // Enemy speed (constant) - also could be modelled as a Vector2
    Vector2 enemyInitialPosition;    // Invader/enemy initial position;
    int R1, R2;                     // casting and "action" radius of the Ultimate

    Vector2 difference;             // Vector of the difference of positions between the players
    Vector2 enemyFinalPosition;     // Vector of the difference of positions between the players
    int totalRange;                 // R1 + R2 ; the maximum radius that the Ultimate can reach
    
    float differenceMag;            
    Vector2 normalizedDifference;
    Vector2 finalDifference;
    Vector2 enemyDisplacement;
    float finalDifferenceMag;       
        
    while (scanf("%f", &heroPosition.x) == 1)
    {
        scanf("%f", &heroPosition.y);
        scanf("%f", &enemyInitialPosition.x);
        scanf("%f", &enemyInitialPosition.y);
        scanf("%f", &Vi);
        scanf("%f", &R1);
        scanf("%f", &R2);

        printf("[DEBUG]Hero Initial Position: "); printVector(heroPosition);
        printf("[DEBUG]Enemy Initial Position: "); printVector(heroPosition);

        // Calculating totalRange (since we are on a straight line)
        totalRange = R1 + R2;

        // Calculating the difference Vector (difX, difY) at the instant of the cast of the Ultimate,
        // for the fleing direction (opposite direction)
        
        difference = sum(enemyInitialPosition, inverse(heroPosition));
        printf("[DEBUG]Initial Difference: "); printVector(difference);

        // Normalizing this last vector - just for Debug
        printf("[DEBUG]Normalized Difference: "); printVector(normalized(difference));

        // Note: SPEED is a SCALAR and VELOCITY is a VECTOR unit
        // Assuming the enemy will flee at constant speed and direction (our vector difference above)
        // Let's determine the future position of the enemy when the Ultimate is ready to cast (after the castTime 1.5f)

        enemyDisplacement = multiplicationByScalar(normalized(difference), castTime * Vi);
        enemyFinalPosition = sum(enemyInitialPosition, enemyDisplacement);
        printf("[DEBUG]Enemy Final Position: "); printVector(enemyFinalPosition);
        
        // Remember that it's possible to overshoot our target!
        
        // Let's find if the enemy is inside the Ultimate action radius (our totalRange)
        
        finalDifference = sum(enemyFinalPosition, inverse(heroPosition));
        finalDifferenceMag = magnitude(finalDifference);
        
        // Magnitude of the distance between the players
        printf("[Debug] Final Distance Between Players: %.3f \n", finalDifferenceMag);
        printf("[Debug] Total Cast Range: %d \n", totalRange);

        if (finalDifferenceMag <= totalRange)
        {
            printf("Y\n");  // Yes! Hit the enemy!
        }
        else
        {
            printf("N\n");  // No! Miss the enemy!
        }
    }   // While closing
return 0;
}

// we create the following operations as functions, since in C we can't override a operator (as in C++)

// Adding 2 Vector2's
Vector2 sum(Vector2 firstVector, Vector2 secondVector)
{
    Vector2 outputVector;
    outputVector.x = firstVector.x + secondVector.x;
    outputVector.y = firstVector.y + secondVector.y;
    return outputVector;
}

// Multiplies a Vector2 by a number (scalar)
Vector2 multiplicationByScalar(Vector2 vector, float scalar)
{
    Vector2 outputVector;
    outputVector.x = vector.x * scalar;
    outputVector.y = vector.y * scalar;
    return outputVector;
}

// Return a inverse (addictive) Vector2 - could be used to perform subtractions
Vector2 inverse(Vector2 vector)
{
    Vector2 outputVector;
    outputVector.x = -vector.x;
    outputVector.y = -vector.y;
    return outputVector;
}

// a auxiliary debug function that print a Vector2 to stdout
void printVector(Vector2 vector)
{
    printf("(%.3f, %.3f)\n", vector.x, vector.y);
}

// return the magnitude (size) of a vector - float value
float magnitude(Vector2 vector)
{
    return sqrt(vector.x*vector.x + vector.y*vector.y);
}

// Returns this vector with a magnitude of 1 (Read Only).
// When normalized, a vector keeps the same direction but its length is 1.0.
// Note that the current vector is unchanged and a new normalized vector is returned.
Vector2 normalized(Vector2 vector)
{
    Vector2 outputVector;
    float mag;
    mag = magnitude(vector);
    outputVector.x = vector.x / mag;
    outputVector.y = vector.y / mag;
    return outputVector;
}