# Throwing Cards Away #1110
# Dalton Lima 07/28/17
# https://www.urionlinejudge.com.br/judge/en/problems/view/1110
# More problems @github.com/daltonbr/uri

import sys

# Input is a ordered deck of n cards numbered 1 to n
# with card 1 at the top and card n at the bottom

# The following operation is performed as long as there are at least
# two cards in the deck:
# Throw away the top card and move the card that is now on the top of the deck
# to the bottom of the deck.

for line in sys.stdin:
    
    input_n = line

    # Grab input and validate it (not really necessary, if we assume a perfect scenario)
    try:
        deck_size = int(input_n)
    except ValueError as error:
        print("Input must be an integer!")
        print(error)
        sys.exit()

    # while deck_size != 0:
    if (deck_size != 0):
        discarded = []
        initial_deck = list(range(1, deck_size+1))
        print (initial_deck, sep=', ')

        while (len(initial_deck) > 1):
            # throw away the head (the first element in the list)
            discarded.append(initial_deck.pop(0))
        #       print (initial_deck, sep=', ')   
            
            # check again if count > 1
            if (len(initial_deck) > 1):
                # move the new head through the end (bottom) of the list
                poped = initial_deck.pop(0)
        #           print (initial_deck, sep=', ')    
                initial_deck.append(poped)
        #           print (initial_deck, sep=', ')
        
        print("Discarded cards:", sep=", ")
        print(discarded, sep=", ")
        print("Remaining card:")
        print(initial_deck[0])    
    else:     
        sys.exit()
