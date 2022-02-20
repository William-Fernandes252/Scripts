import pymysql
import pymysql.cursors
from contextlib import contextmanager


@contextmanager
def connect():
    connection = pymysql.connect(
        host='127.0.0.1',
        user='root',
        password='',
        db='clientes',
        charset='utf8mb4',
        cursorclass=pymysql.cursors.DictCursor
    )
    
    try:
        yield connection
    finally:
        connection.close()

      
# Insert one registry in the database   
# with connect() as connection:
#     with connection.cursor() as cursor:
#         query = 'INSERT INTO clientes (nome, sobrenome, idade, peso) VALUES (%s, %s, %s, %s)'
#         cursor.execute(query, ('Jack', 'Monroe', 112, 67))
#         connection.commit()

# Insert a list of registries in the database
# with connect() as connection:
#     with connection.cursor() as cursor:
#         query = 'INSERT INTO clientes (nome, sobrenome, idade, peso) VALUES (%s, %s, %s, %s)'
#         data = [
#             ('Monael', 'Ribeiro', 45, 67),
#             ('John', 'Walker', 60, 70),
#             ('Historia', 'Reiss', 14, 55),
#         ]
#         cursor.executemany(query, data)
#         connection.commit()

# Delete registries from the database that correspond to the specified ids
# with connect() as connection:
#     with connection.cursor() as cursor:
#         query = 'DELETE FROM clientes WHERE id IN (%s, %s)'
#         cursor.execute(query, (4, 5))
#         connection.commit()

# Delete registries whose id is in specified interval.
# with connect() as connection:
#     with connection.cursor() as cursor:
#         query = 'DELETE FROM clientes WHERE id BEETWEEN %s AND %s'
#         cursor.execute(query, (4, 5))
#         connection.commit()

# Update a registry in the database
# with connect() as connection:
#     with connection.cursor() as cursor:
#         query = 'UPDATE clientes SET nome=%s WHERE id=%s'
#         cursor.execute(query, ('Alice', 3))
#         connection.commit()

#Read data from the database
with connect() as connection:
    with connection.cursor() as cursor:
        cursor.execute('SELECT id, nome as name, sobrenome as surname FROM clientes ORDER BY ID DESC')
        results = cursor.fetchall()
        for line in results:
            print(line)
        
