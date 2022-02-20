from data import *
from functools import reduce

sum_list = reduce(lambda ac, i: i + ac, l, 0)

# print(sum_list)

sum_prices = reduce(lambda ac, p: p['price'] + ac, products, 0)

# print(sum_prices/len(products))

sum_ages = reduce(lambda ac, p: ac + p['age'], people, 0)

average_age = sum_ages/len(people)

print(average_age)