# Plus Minus
# https://www.hackerrank.com/challenges/plus-minus/problem

#!/bin/python3

import sys

def plusMinus(arr):
    positiveCount = 0
    negativeCount = 0
    zeroesCount = 0
    for element in arr:
        if element > 0:
            positiveCount += 1
        elif element == 0:
            zeroesCount += 1
        else:
            negativeCount += 1
    
    totalCount = positiveCount + negativeCount + zeroesCount
    print(positiveCount/totalCount, negativeCount/totalCount, zeroesCount/totalCount, sep='\n')


if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    plusMinus(arr)
