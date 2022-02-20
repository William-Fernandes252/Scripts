import sqlite3
import re


class PhonebookDB:
    def __init__(self, dbpath = 'dbs/phonebook.db'):
        self.__connection = sqlite3.connect(dbpath)
        self.__cursor = self.__connection.cursor()
        
    def insert(self, name, phone):
        if not self._validatephone(phone):
            print("Invalid phone number.")
        try:
            query = 'INSERT OR IGNORE INTO phonebook (name, phone) VALUES (?, ?)'
            self.__cursor.execute(query, (name, phone))
            self.__connection.commit()
            return True
        except Exception as error:
            print(error)
            return False

    def update(self, id, **kwargs):
        self.__cursor.execute('SELECT name, phone FROM phonebook WHERE id = ?', (id,))
        name, phone = self.__cursor.fetchone()
        
        if not kwargs['name'] and not kwargs['phone']:
            print('No updated data was specified.')
            return False
        
        if kwargs['name']:
            name = kwargs['name']
        if kwargs['phone']:
            phone = kwargs['phone']
        
        if not self._validatephone(phone):
            print("Invalid phone number.")
            return False
        
        try:
            query = 'UPDATE OR IGNORE phonebook SET name = ?, phone = ? WHERE id = ?'
            self.__cursor.execute(query, (id, name, phone))
            self.__connection.commit()
            return True
        except Exception as error:
            print(error)
            return False

    def delete(self, id):
        try:
            query = 'DELETE FROM phonebook WHERE id = ?'
            self.__cursor.execute(query, (id,))
            self.__connection.commit()
            return True
        except Exception as error:
            print(error)
            return False

    def read(self):
        try:
            self.__cursor.execute('SELECT * FROM phonebook')
            return self.__cursor.fetchall()
        except Exception as error:
            print(error)
        
    def execute(self, query):
        try:
            self.__cursor.execute(query)
            return True
        except Exception as error:
            print(error)
            
    def close(self):
        self.__cursor.close()
        self.__connection.close()
    
    @staticmethod   
    def _validatephone(phone):
        validator = re.compile(r'^\([0-9]{2}\)[0-9]{4,5}-[0-9]{4}$')
        if validator.match(phone):
            return True
        
        

if __name__ == '__main__':
    phonebook = PhonebookDB()
    phonebook.insert('William', '(11)96485-8088')
    phonebook.insert('Tatiane', '(11)98020-7076')
    phonebook.insert('Renata', '(11)95323-3425')
    phonebook.update(1, name = 'Willian', phone = '(11)96485-8086')
    data = phonebook.read()
    for id, name, phone in data:
        print(name, phone, sep='\t')