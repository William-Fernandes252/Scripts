from credentials import cpf, cnpj
from abc import ABC, abstractmethod
from re import fullmatch
from bank.errors import AuthenticationError, ValidationError

class User:
    def __init__(self, name, age, access):
        self._name = name
        self._age = age
        self._access = access
        self._accounts = []
        self.adresses = []
    
    def add_address(self, city, state):
        self.adresses.append(Adress(city, state))
        
    def add_account(self, account):
        self.accounts.append(account)

    def list_adresses(self):
        for adress in self.adresses:
            print(adress.city, adress.state)
            
    @property
    def access(self):
        return self._access
    
    @access.setter
    def access(self, access):
        if not fullmatch('^[0-9]{4}$', access):
            raise ValidationError("Invalid access.")
        access = self._access
            
    @property
    def age(self):
        return self._age
            
    @age.setter
    def age(self, age):
        if not isinstance(age, int) or age < 18:
            raise ValidationError('Must be at least 18 years old to register.')
        self._age = age
    
    @property
    def accounts(self):
        return self._accounts
            
    def __del__(self):
        print(f'{self._name} was deleted.')

class Client(User, ABC):
    @abstractmethod   
    def _authenticate(access, password, credential):
        pass

class PF(Client):
    def __init__(self, name, age, access, credential):
        super().__init__(name, age, access)
        try:
            self._authenticate(age, access, credential)
        except AuthenticationError as error:
            print(error)
        self._credential = credential
            
    @property
    def credential(self):
        return self._credential
    
    @credential.setter
    def credential(self, credential):
        if not cpf.validate(credential):
            raise ValidationError("Invalid CPF.")
        self._credential = credential   
    
    @staticmethod
    def _authenticate(age, access, credential):
        # Authentication process
        ...
        
        
class PJ(Client):
    def __init__(self, name, age, access, credential):
        super().__init__(name, age, access)
        try:
            self.__authenticate(age, access, credential)
        except AuthenticationError as error:
            print(error)
        self._credential = credential
        
    @property
    def credential(self):
        return self._credential
    
    @credential.setter
    def credential(self, credential):
        if not cnpj.validate(credential):
            raise ValidationError("Invalid CNPJ.")
        self._credential = credential
        
    @staticmethod
    def __authenticate(age, access, credential):
        # Authentication process
        ...
             
            
class Adress:
    def __init__(self, city, state):
        if not self.__is_valid_state(state):
            raise ValidationError("State must a valid state symbol.")
        self.city = city
        self.state = state
    
    @staticmethod  
    def __is_valid_state(state):
        return fullmatch('^[A-Z]{2}$', state)
        
    def __del__(self):
        print(f'{self.city}/{self.state} was deleted.')