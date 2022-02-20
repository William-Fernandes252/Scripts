import sqlite3


connection = sqlite3.connect('dbs/database.db')
cursor = connection.cursor()

# Create tables
# cursor.execute(
#     'CREATE TABLE IF NOT EXISTS clients ('
#     'id INTEGER PRIMARY KEY AUTOINCREMENT,'
#     'name TEXT UNIQUE,'
#     'weight REAL'
#     ')'
# )

# Insert data
# cursor.execute(
#     'INSERT INTO Clients (name, weight) VALUES (?, ?)',
#     ('William', 75.5)
# )
# cursor.execute(
#     'INSERT INTO Clients (name, weight) VALUES (:name, :weight)', 
#     {'name': 'John', 'weight': 67.4}
# )
# cursor.execute(
#     'INSERT INTO Clients VALUES (:id, :name, :weight)', 
#     {'id': None, 'name': 'May', 'weight': 60.6}
# )
# connection.commit()

# Update and delete data
# cursor.execute(
#     'UPDATE clients SET weight = :weight WHERE id = :id',
#     {'id': 3, 'weight': 58.3}
# )
# cursor.execute(
#     'DELETE FROM clients WHERE id = :id',
#     {'id': 3}
# )
# connection.commit()

# Read data
cursor.execute(
    'SELECT name, weight FROM clients WHERE weight > :weight',
    {'weight': 50}          
)
for line in cursor.fetchall():
    name, weight = line
    print(name, weight)
    
cursor.close()
connection.close()