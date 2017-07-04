import fileinput

for line in fileinput.input():
    #print("line read: ", line)
    value_list = line.split()

    # Converting str to int ... with list comprehension
    int_list = line.split()
    int_list = [int(i) for i in int_list]

    # ... or we could user map function also
    # int_list = list(map(int, int_list))

    # it's a simple bitwise xor (operator ^)
    print(int_list[0] ^ int_list[1])
