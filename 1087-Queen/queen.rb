##
# Queen #1087
# Dalton Lima 11/10/17
# https://www.urionlinejudge.com.br/judge/en/problems/view/1087
# More problems @github.com/daltonbr/uri

# The game of Chess has several pieces with curious movements.
# One of them is the Queen, which can move any number of squares in
# any direction: in the same line, in the same column or in any of 
# the diagonals.

# The great Chess Master Gary Gasparov invented a new type of chess
# problem: given the position of a queen in an empty standard chess 
# board (that is, an 8 x 8 board) how many moves are needed so that
# she reaches another given square in the board?

# Gary found the solution for some of those problems, but is having
# a difficult time to solve some others, and therefore he has asked 
# that you write a program to solve this type of problem.

# -- Input --
# The input contains several test cases. The only line of each test
# case contains four integers X1, Y1, X2 and Y2 (1 ≤ X1, Y1, X2, Y2 ≤ 8).
# The queen starts in the square with coordinates (X1, Y1), and must
# finish at the square with coordinates (X2, Y2).
# In the chessboard, columns are numbered from 1 to 8, from left ro right;
# lines are also numbered from 1 to 8, from top to bottom.
# The coordinates of a square in line X and column Y are (X, Y).

# The end of input is indicated by a line containing four zeros,
# separated by spaces.

# -- Output --
# For each test case in the input your program must print a single
# line, containing an integer, indicating the smallest number of 
# moves needed for the queen to reach the new position.

# Input Sample	Output Sample
# 4 4 6 2       1
# 3 5 3 5       0
# 5 5 4 3       2
# 0 0 0 0

# while not end of stream (0 0 0 0)
loop do

  # Read, chomp and split the user input
  user_input = gets.chomp
  break if user_input == "0 0 0 0"

  parsed_input = user_input.split(" ")
  
  x1 = parsed_input[0].to_i
  y1 = parsed_input[1].to_i
  x2 = parsed_input[2].to_i
  y2 = parsed_input[3].to_i

  # test for horizontal and vertical (and same position)
  if x1 == x2 or y1 == y2
    if x1 == x2 and y1 == y2
      puts "0" # same position
      next
    end
    puts "1" # horizontal or vertical
    next
  end
  
  # test for diagonals
  delta_x = (x2 - x1).abs
  delta_y = (y2 - y1).abs

  if delta_x == delta_y
    puts "1" # diagonals
  else
    puts "2" # any other case
  end

end 