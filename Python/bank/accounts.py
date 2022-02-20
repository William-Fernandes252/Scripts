from abc import ABC, abstractmethod
from bank.errors import ValidationError
from re import fullmatch
from bank import Bank


class Account(ABC):
    def __init__(self, bank, agency_number, account_number, password, owner_credential, balance = 0):
        """Initiates a new account object.

        Args:
            agency (str): A 5 digit agency number.
            account (str): A 7 digit account number.
            password (str): A 6 digit password number.
            balance (float, optional): The account initial balance. Defaults to 0.
            owner_credential (str): The credential (cpf or cnpj) of the account owner.
        """
        self.agency_number = agency_number
        self.account_number = account_number
        self.balance = balance
        self.password = password
        self._owner = owner_credential
        self.bank = bank
        bank.add_account(self)
        
    @property
    def agency_number(self):   
        return self._agency_number
    
    @property
    def account_number(self):
        return self._account_number
    
    @property
    def balance(self):
        return self._balance
    
    @property
    def password(self):
        return self._password
    
    @property
    def owner(self):
        return self._owner
    
    @balance.setter
    def balance(self, value):
        if not isinstance(value, (int, float)):
            raise ValueError("Balance must be numeric.")
        self._balance = value
        
    @agency_number.setter
    def agency_number(self, agency):
        if not fullmatch('^[0-9]{5}', agency):
            raise ValidationError("Invalid agency number.")
        self._agency_number = agency
        
    @account_number.setter
    def account_number(self, account):
        if not fullmatch('^[0-9]{7}$', account):
            raise ValidationError("Invalid account number.")
        self._account_number = account
        
    @password.setter
    def password(self, password):
        if not fullmatch('^[0-9]{6}', password):
            raise ValidationError("Invalid password.")
        self._password = password
      
    def details(self):
        print(
            f'\nAgency: {self.agency_number}',
            f'Account: {self.account_number}',
            f'Balance: R${self.balance:.2f}\n',
            sep='\n'
        )
        
    def deposit(self, value: float):
        try:
            numeric = float(value)
        except:
            raise ValueError("Value must be a valid amount to deposit.")
        self.balance += numeric
             
    # Different types of accounts states different rules 
    # to treat withdraws.
    @abstractmethod 
    def withdraw(self, value: float, password, agency, account, credential):
        pass
    
    
class SavingsAcc(Account):
    def withdraw(self, value: float, password, user):
        try:
            numeric = float(value)
        except ValueError:
            print("Value must be valid amount to withdraw.")
            return
        if not Bank.authorize_withdraw(self.bank, self, password, user):
            print("Operation denied.")
            return
        elif self.balance < numeric:
            print('Insufficient balance.')
            return
        self.balance -= numeric
        
        
class CurrentAcc(Account):
    def __init__(self, agency, account, password, balance = 0, limit = 100.00):
        super().__init__(agency, account, password, balance)
        self._limit = limit
        
    @property
    def limit(self):
        return self._limit
    
    @limit.setter
    def limit(self, limit):
        try:
            numeric = float(limit)
        except ValueError:
            print("Operation failed. Limit must be numeric.")
        if not self.__is_valid_limit(numeric):
            raise ValueError("Invalid limit.")
        self._limit = numeric
    
    @staticmethod
    def __is_valid_limit(limit):
        return not (limit > 500 or limit < 0)

    def withdraw(self, value: float, password, user):
        try:
            numeric = float(value)
        except ValueError:
            print("Value must be valid amount to withdraw.")
            return
        if not Bank.authorize_withdraw(self.bank, self, password, user):
            print("Operation denied.")
            return
        elif (self.balance + self.limit) < numeric:
            print('Insufficient balance.')
            return
        self.balance -= numeric
    
        
if __name__ == '__main__':
    sv = SavingsAcc('1111', '2222', 0)
    sv.deposit(300)
    sv.details()
    print()
    sv.withdraw(250)
    sv.details()
    
    print()
    
    sv = CurrentAcc('3333', '4444', 0, 500)
    sv.deposit(3000)
    sv.details()
    print()
    sv.withdraw(3250)
    sv.details()