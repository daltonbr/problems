# Problem #1026
# Author: Dalton Lima @daltonbr
# 07/04/17
# https://www.urionlinejudge.com.br/judge/en/problems/view/1068

import fileinput

# for line in fileinput.input():


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

my_stack = Stack()

a_string="abcd(abc(lkj)"
for letter in a_string:
    if letter == '(':
        print("Opening")
        my_stack.push(letter)
    if letter == ')':
        print("Closing")
        my_stack.pop()
        # if pop failed -> 'incorrect'

if my_stack.is_empty():
    print('correct')
else:
    print('incorrect')