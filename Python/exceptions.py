from sys import exit

try:
    x = int(input("x: "))
    y = int(input("y: "))
except ValueError:
    print("Error: invalid input.")
    exit(1)
    
try:
    result = x/y
except ZeroDivisionError:
    print("Error: canot divide by zero.")
    exit(1)
    
print(f"{x} / {y} = {result}")