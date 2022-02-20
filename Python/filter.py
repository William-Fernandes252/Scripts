from data import *

# filtered_list = filter(lambda x: x > 5, l)
filtered_list = [x for x in l if x > 5]

# print(list(filtered_list))

filtered_products = filter(lambda p: p['price'] > 50.0, products)

# for product in filtered_products:
#     print(product)
    
children = filter(lambda p: p['age'] < 10, people)

for child in children:
    print(child)