''' 
Dalton Lima - 09-22-17
Giovanni Burigo

Read two floating points' values of double precision A and B,
corresponding to two student's grades. After this, calculate
the student's average, considering that grade A has weight
3.5 and B has weight 7.5. Each grade can be from zero to 
ten, always with one digit after the decimal point. Don’t
forget to print the end of line after the result, otherwise
you will receive “Presentation Error”. Don’t forget the
space before and after the equal sign.

Input

The input file contains 2 floating points' values with one
 digit after the decimal point.

Output

Print MEDIA(average in Portuguese) according to the following
 example, with 5 digits after the decimal point and with a
 blank space before and after the equal signal.
'''
user_input1 = input()
user_input2 = input()

x = float(user_input1)
y = float(user_input2)

w1 = 3.5
w2 = 7.5
w_total = w1 + w2

x_weighted = x * w1 # 4  
y_weighted = y * w2 # 6 

average = (x_weighted + y_weighted) / w_total

print ('MEDIA = {0:.5f}' .format(average))
