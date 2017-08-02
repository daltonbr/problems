# Problem #1026
# Author: Dalton Lima @daltonbr
# 07/04/17
# https://www.urionlinejudge.com.br/judge/en/problems/view/1068

import fileinput

class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)



def check_parenthesis(line):
    line = line.strip('\n')
    my_stack = Stack()

    for character in line:
        if character == '(':
            # print("--Opening--")
            my_stack.push(character)
        if character == ')':
            # print("--Closing--")
            try:
                my_stack.pop()
            except IndexError as error:
                # print(error, " - Sintax error: There are more ')' than '('")
                print('incorrect')
                return

    # we finish reading the string
    if my_stack.is_empty():
        print('correct')
    else:
        print('incorrect')

# main
for line in fileinput.input():
    check_parenthesis(line)
