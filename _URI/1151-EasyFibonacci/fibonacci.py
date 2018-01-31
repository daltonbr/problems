# Easy Fibonnaci #1151
# Dalton Lima 07/02/17 
# More problems @github.com/daltonbr/uri

import sys

user_input = input()

# Grab user's input
try:
	total_terms = int(user_input)
except ValueError as error:
	print("Input must be an integer!")
	print(error)
	sys.exit()

term = 0
next_term = 1

print(term, end=' ')
if (total_terms == 1):
	sys.exit()

for i in range(1, total_terms-1):
	print(next_term, end=' ')
	aux = next_term
	next_term += term
	term = aux

# last term doesn't have a space after it (as requested)
print(next_term)