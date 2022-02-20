def generator():
    for g in range(0, 100):
        yield g

g = generator()
for i in g:
    print(i)