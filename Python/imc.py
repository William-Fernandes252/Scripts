from datetime import datetime, timedelta

name = input("Name: ")
height = float(input("Height: "))
weight = float(input("Weight: "))
birth = int(input("Birth (year): "))
present_year = datetime.now().year
age = present_year - birth
imc = weight/(height**2)

print(f"{name.capitalize()} have {age} years, measures {height:.2f} meters and weights {weight:.2}kg.\nThe {name}'s IMC is {imc:.2f}.\n{name} was born in {birth}.")