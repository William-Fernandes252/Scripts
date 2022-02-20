class Product:
    def __init__(self, name, price):
        self.name = name
        self.price = price
        
    def discount(self, percentage):
        self.price -= self.price * (percentage/100)
        
    # Name Getter
    @property
    def name(self):
        return self._name
    
    # Name Setter
    @name.setter
    def name(self, name):
        self._name = name.title().replace('@', 'a')
        
    # Price Getter
    @property
    def price(self):
        return self._price
    
    # Price Setter
    @price.setter
    def price(self, value):
        if isinstance(value, str):
            value = float(value.replace('R$', '')) 
        self._price = value
        

class Cart:
    def __init__(self):
        self.products = []
        
    def add_product(self, product):
        self.products.append(product)
        
    def list_products(self):
        for product in self.products:
            print(product.name, f'{product.price:.2f}')
    
    @property     
    def total_price(self):
        total = 0
        for product in self.products:
            total += product.price
        return total

       
if __name__ == '__main__':
    p1 = Product('SHIRT', 50)
    p1.discount(10)
    p2 = Product('UMBRELL@', 'R$15')
    p2.discount(15)
    p3 = Product('termic bottle', 'R$30')
    p3.discount(20)

    cart = Cart()
    cart.add_product(p1)
    cart.add_product(p2)
    cart.add_product(p3)
    
    cart.list_products()
    print(cart.total_price)