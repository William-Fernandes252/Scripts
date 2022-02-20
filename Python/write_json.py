import json

d = {
    'user1': {
        'name': 'John',
        'age': 18,
    },
    'user2': {
        'name': 'Marie',
        'age': 20,    
    },
}

djson = json.dumps(d)

with open('users.json', 'w+') as users:
    users.write(djson)