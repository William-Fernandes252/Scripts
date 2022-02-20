from cmath import e
from re import I
from types import CellType
from log import LogMixin

class Eletronic:
    def __init__(self, name):
        self._name = name
        self._on = False

    def turnon(self):
        if self._on:
            return
        self._on = True
    
    def turnoff(self):
        if not self._on:
            print(f'{self._name} is already off.')
            return
        self._on = False
        
        
class Smartphone(Eletronic, LogMixin):
    def __init__(self, name):
        super().__init__(name)
        self._connected = False
        
    def connect(self):
        if not self._on:
            error = f'{self._name} is not on.'
            print(error)
            self.log_error(error)
            return
        elif self._connected:
            error = f'{self._name} is already connected.'
            print(error)
            self.log_error(error)
            return
        info = f'{self._name} is connected.'
        print(info)
        self.log_info(info)
        self._connected = True
        
    def disconnect(self):
        if not self._connected:
            error = f'{self._name} is not connected.'
            print(error)
            self.log_error(error)
            return
        info = f'{self._name} was disconnected.'
        print(info)
        self.log_info(info)
        self._connected = False
            

if __name__ == '__main__':
    cellphone = Smartphone('Zenphone Pro m1')
    cellphone.connect()
    cellphone.turnoff()
    cellphone.turnoff()
    cellphone.turnon()
    cellphone.connect()
    cellphone.connect()
    cellphone.turnon()
    cellphone.disconnect()
    cellphone.turnoff()