"""
Encryption (string manipulations)
https://www.urionlinejudge.com.br/judge/en/problems/view/1024
"""

NUMBER_LINES = int(input())

for i in range(NUMBER_LINES):
    line = input()

    reversed_shifted_string = ''
    # increment a char 3 positions only when it is an alpha (a-zA-Z)
    for element in reversed(line):
        if element.isalpha():
            reversed_shifted_string += chr(ord(element)+3)
        else:
            reversed_shifted_string += element

    half_size = len(reversed_shifted_string) // 2

    # second half (truncated) of the string decrements 1 position
    new_second_half = ''
    for element in reversed_shifted_string[half_size:]:
        new_second_half += chr(ord(element)-1)

    print(reversed_shifted_string[:half_size], new_second_half, sep='')
    