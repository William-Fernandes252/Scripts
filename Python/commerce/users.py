from credentials import cpf, cnpj

class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
        self.adresses = []
    
    def add_address(self, city, state):
        self.adresses.append(Adress(city, state))

    def list_adresses(self):
        for adress in self.adresses:
            print(adress.city, adress.state)
            
    def __del__(self):
        print(f'{self.name} was deleted.')

class Client(Person):
    def __init__(self, name, age, cpf):
        super(Client, self).__init__(name, age)
        client_cpf = cpf.generate()

class Seller(Person):
    def __init__(self, name, age, cnpj):
        super(Seller, self).__init__(name, age)
        seller_cnpj = cnpj.generate()
            
class Adress:
    def __init__(self, city, state):
        self.city = city
        self.state = state
        
    def __del__(self):
        print(f'{self.city}/{self.state} was deleted.')