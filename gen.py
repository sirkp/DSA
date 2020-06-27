import random
import sys

def generate_no(start, end):
    n = random.randrange(start, end)
    print(n)

def generate_arr(start, end, n=0):
    if (n==0):
        n = random.randrange(start, end)
    print(n)    
    for i in range(n):
        print(random.randrange(start, end), end =" ")
    print('')

if (len(sys.argv)<=1):
    print("input: option start end n, n is given when option is 2")
    print("option-0 for a no\noption-1 for arr with random size\noption-2 for arr with fixed size")
    inp = input("input: ")
    inp = inp.split()
else: 
    inp = sys.argv[1:]
    inp = [int(e) for e in inp]

if (inp[0] == 0):
    generate_no(inp[1], inp[2])
elif (inp[0] == 1):
    generate_arr(inp[1], inp[2])
else:        
    generate_arr(inp[1], inp[2], inp[3])