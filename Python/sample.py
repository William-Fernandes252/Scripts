from sys import argv, exit
from random import choice
from itertools import combinations

WORD = "IDENTIDADE"

if len(argv) != 2:
    print("Usage: sample.py <number of samples>")
    exit(1)
    
try:
    samples = int(argv[1])
except:
    raise ValueError("Invalid parameter. Must be a positive integer.")

r = list(combinations(WORD, 2))

weight = 0.0
for i in range(samples):
    pair = choice(r)
    if pair[0] != pair[1]:
        weight += 0.5
    else:
        weight += 1

print(weight/samples)