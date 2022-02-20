from commerce.users import Client

client1 = Client('Maria', 23)
client1.add_address('Belo Horizonte', 'MG')
print(client1.name)
client1.list_adresses()
del client1
print()

client2 = Client('Jonh', '32')
client2.add_address('Salvador', 'BA')
client2.add_address('Rio de Janeiro', 'RJ')
print(client2.name)
client2.list_adresses()
del client2
print()

client3 = Client('Peter', 45)
client3.add_address('São Paulo', 'SP')
print(client3.name)
client3.list_adresses()
del client3
print()