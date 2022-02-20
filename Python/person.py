from datetime import datetime
from random import randint

class Person:
    current_year = int(datetime.strftime(datetime.now(), '%Y'))

    def __init__(self, nome, age, eating=False, speaking=False):
       self.name = nome
       self.age = age
       self.eating = eating
       self.speaking = speaking

    def speak(self, subject):
        if self.eating:
            print(f'{self.name} cannot speak while eating.')
            return

        if self.speaking:
            print(f'{self.name} is already speaking.')
            return

        print(f'{self.name} is speaking about {subject}.')
        self.speaking = True

    def stop_speaking(self):
        if not self.speaking:
            print(f'{self.name} is not speaking now.')
            return

        print(f'{self.name} stopped to speak.')
        self.speaking = False

    def eat(self, alimento):
        if self.eating:
            print(f'{self.name} is already eating.')
            return

        if self.speaking:
            print(f'{self.name} cannot eat while speaking.')
            return

        print(f'{self.name} is eating {alimento}.')
        self.eating = True

    def stop_eating(self):
        if not self.eating:
            print(f'{self.name} is not eating.')
            return

        print(f'{self.name} stopped to eat.')
        self.eating = False

    def get_birth_year(self):
        return self.current_year - self.age
    
    @classmethod
    def per_birth_year(cls, name, birth_year):
        age = cls.current_year - birth_year
        return cls(name, age)
    
    @staticmethod
    def generate_id():
        id = randint(10000, 99999)
        return id
    

if __name__ == '__main__':
    p1 = Person('Nathan', 29)
    p2 = Person('Dany', 32)
    p3 = Person.per_birth_year('Alice', 2002)

    print(p1.get_birth_year())
    print(p2.get_birth_year())
    print(p3.age)
    print(Person.generate_id())