from credentials.cnpj import generate
from sys import argv, exit

    
if len(argv) > 2:
    print("Usage: gencnpj.py n? (number of valid CNPJs to generate, default is one).")
    exit(1)
    
try:
    cnpjs = generate(int(argv[1]))
except:
    cnpjs = generate()
    
print(cnpjs)