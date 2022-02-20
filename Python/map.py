from data import products, people, l

def elevate_price(product):
    product['price'] = round(product['price'] * 1.10, 2)
    return  product

def is_adult(person):
    person['adult'] = person['age'] >= 18
    return person

new_list = map(lambda x: x * 2, l)
# print(list(new_list))

prices = map(lambda p: p['price'] * 1.05, products)

new_products = map(elevate_price, products)

# for product in new_products:
#     print(product)
    
people_updated = map(is_adult, people)

[print(person) for person in people_updated]