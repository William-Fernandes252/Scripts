def number(str):
    try:
        return int(str)
    except ValueError:
        try:
            return float(str)
        except ValueError:
            pass

while True:    
    n = number(input('Enter a number: '))
    if n is not None:   
        print(f'{n} * 5 = {n * 5}')
    else:
        print('This is not a number.')