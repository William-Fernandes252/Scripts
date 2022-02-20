class Array:
    def __init__(self):
        self.__items = []
        self.__index = 0
    
    def add(self, value):
        self.__items.append(value)
        
    def __getitem__(self, index):
        self.__check_index(index)
        return self.__items[index]
    
    def __setitem__(self, index, value):
        self.__check_index(index)
        if index >= len(self.__items):
            self.__items.append(value)
            return
        self.__items[index] = value
        
    def __delitem__(self, index):
        self.__check_index(index)
        if index > len(self.__items):
            raise IndexError(f"Index out of range.")
        del self.__items[index]
        
    def __iter__(self):
        return self
    
    def __next__(self):
        try:
            item = self.__items[self.__index]
            self.__index += 1
            return item
        except IndexError:
            raise StopIteration
        
    def __str__(self):
        return f'{self.__class__.__name__}({self.__items})'
    
    def __repr__(self):
        return self.__str__()
    
    def __check_index(self, index):
        if not isinstance(index, int):
            raise TypeError(f"Index must be an integer, not {type(index)}.")
        elif value < 0:
            raise ValueError(f"Index must be a positive integer.")
    
if __name__ == '__main__':
    array = Array()
    array.add(1)
    array.add(2)
    for value in array:
        print(value)