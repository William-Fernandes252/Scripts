from random import choices
from string import digits, ascii_letters
from sys import argv, exit


def genpwd(size = 6):
    try:
        size = int(size)
    except ValueError:
        print(f"Invalid size. Expected positive integer, got {type(size)}.")
        exit(1)
        
    if size < 0:
        raise ValueError("Invalid size. Expected positive integer.")
        
    characters = ascii_letters + digits + '!@#$%&*._-?'
    password = ''.join(choices(characters, k = size))
    print(password)
    return password
  
  
if __name__ == '__main__':
    if len(argv) != 2:
        print('Usage: randpwd size')
        exit(1)
        
    genpwd(argv[1])