class Bank:
    def __init__(self, name):
        """Initiates a new Bank.

        Args:
            name (str): The bank name.
        """
        self._name = name
        self._agencies = []
        self._clients = []
        self._accounts = []
        
    def add_agency(self, agency):
        self._agencies.append(agency)
        
    def add_client(self, client):
        self._clients.append(client)
        
    def add_account(self, account):
        if account.agency_number not in [agency.agency_number for agency in self.agencies]:
            print('Invalid agency number.')
            return
        elif account.owner not in [client.credential for client in self.clients]:
            print('You are not a client.')
            return
        self._accounts.append(account)
        
    def authorize_withdraw(bank, account, password, client):
        if client not in bank.clients:
            print('You are not a client.')
            return False
        elif account not in client.accounts:
            print('You are not the owner of the account.')
            return False
        elif account not in bank.accounts:
            print('Invalid account.')
            return False
        elif account.agency_number not in [agency.agency_number for agency in bank.agencies]:
            print('This account does not exist in this agency.')
            return False
        elif password != account.password:
            print('Wrong password.')
            return False
        return True

        
    @property
    def name(self):
        return self._name
    
    @property
    def agencies(self):
        return self._agencies
    
    @property
    def clients(self):
        return [client for client in self._clients]
    
    @property
    def accounts(self):
        return [acc for acc in self._accounts]

class Agency:
    def __init__(self, agency_number):
        """Initiates a new agency.

        Args:
            agency (str): The 5 digit agency number of the bank.
        """
        self._agency_number = agency_number
        self._accounts = []
        
    @property
    def agency_number(self):
        return self._agency_number