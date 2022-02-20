from dataclasses import dataclass, field, asdict, astuple

@dataclass(eq=True, repr=True, order=True, frozen=False, init=True)
class Person:
    name: str
    surname: str = field(repr=False)
    
    def __posr_init__(self):
        if not isinstance(self.name, str):
            raise TypeError(f"Invalid type {type(self.name)} != str on {self}")
        if not isinstance(self.surname, str):
            raise TypeError(f"Invalid type {type(self.surname)} != str on {self}")
        
    @property
    def fullname(self):
        return f'{self.name} {self.surname}'
    
p1 = Person('Will', 'Fernandes')
p2 = Person('Historia', 'Reiss')
p3 = Person('Alice', 'Mendes')

people = sorted([p1, p2, p3], key=lambda person: person.name, reverse=True)

print(asdict(p1))
print(astuple(p2))
print(p3)
print(people)