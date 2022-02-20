from time import time, sleep

def runtime(function):
    def tracktime(*args, **kwargs):
        start = time()
        result = function(*args, **kwargs)
        end = time()
        delta = (end - start) * 1000
        print(f'\nThe function {function.__name__} was executed in {delta:.2f} seconds.')
        return result
    return tracktime

@runtime    # count = runtime(count)
def count():
    for i in range(5):
        sleep(1)
        print(i, end='')
        
count()