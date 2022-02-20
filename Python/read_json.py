import json

with open('users.json') as file:
    users = json.loads(file.read())

for user, info in users.items():
    print(user)
    for name, age in info.items():
        print(name, age)
        
