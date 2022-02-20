def division(n1, n2):
    # try:
    #     return n1/n2
    # except ZeroDivisionError as error:
    #     print(error)
    if n2 == 0:
        raise ValueError('Cant divide by zero')
    return n1/n2

# try:
#     print(division(2, 0))
# except ZeroDivisionError as error:
#     print(str(error) + ' (raised error)')

try:
    print(division(2, 0))
except ValueError as error:
    print('You are trying to divide by zero.')
    print('Log:', error)