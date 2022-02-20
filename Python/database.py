from itertools import count

"""
_ protected: A convenience followed by Python developer that states that class attributes or methods which name begins with a underscore must not be assigned.

__ private: Attributes and methods which names begin with two underscores are renamed to _{ClassName}__{attribute or method} during execution in order to avoid (discourage) both access or assinment. That behavior simulates the "private" functionallity of other Object Oriented languages.
"""

class Database:
    client_auto_id = count(1)
    
    def __init__(self):
        self.__data = {}
        
    @property
    def data(self):
        return self.__data

    def insert_client(self, name):
        id = next(Database.client_auto_id)
        if 'clients' not in self.__data:
            self.__data['clients'] = {id: name}
        else:
            self.__data['clients'].update({id: name})
            
    def list_clients(self):
        for id, name in self.__data['clients'].items():
            print(id, name)

    def delete_clients(self, id):
        del self.__data['clients'][id]
        

if __name__ == '__main__':
    db = Database()
    db.insert_client('Nathan')
    db.insert_client('Alex')
    db.insert_client('Rose')
    db.insert_client('Pam')
    db.insert_client('May')
    db.insert_client('Julia')
    db.insert_client('Fabio')
    db.insert_client('Caio')
    db.delete_clients(2)
    db.list_clients()
    print(db._Database__data)
    print(db.data)
    