from time import sleep

def sleepy(target):
    def spell(*args, **kwargs):
        for i in range(10):
            print('z', end=' ')
            sleep(1)
        print('\nSorry! I was sleeping! Here is your answer.')
        return target(*args, **kwargs)
    return spell

@sleepy
def square(x):
    return x * x

print(square(5))