from credentials.cpf import generate
from sys import argv, exit

    
if len(argv) > 2:
    print("Usage: gencpf.py n? (number of valid CPFs to generate, default is one).")
    exit(1)
    
try:
    cpfs = generate(int(argv[1]))
except:
    cpfs = generate()
    
print(cpfs)