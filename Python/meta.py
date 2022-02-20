class Meta(type):
    def __new__(cls, name, bases, namespace):
        if name != 'A' and 'attr' in namespace:
            del namespace['attr']
        return super().__new__(cls, name, bases, namespace)
            
class A(metaclass=Meta):
    attr = 'a'
    
class B(A):
    attr = 'b'
    def hello():
        print('Hello.')
    
class C(B):
    attr = 'c'
    def mult(x, y):
        return x * y
    
a = A()
b = B()
c = C()

print(a.attr)
print(b.attr)
print(c.attr)