from functools import reduce
from utils import LenError

class Vector(list):
    
    def __init__(self, *args):
        try:
            if not isinstance(args[0][0], (int, float)):
                raise TypeError("Vector must be numeric.") 
            super().__init__(args[0])
        except IndexError:
            super().__init__()
          
    def double(self):
        """Doubles all the elements of an vector"""
        return [i * 2 for i in self]

    def cumulative_product(self):
        """Computes the cumulative product of all the elements of an array"""
        return reduce(lambda ac, x: ac * x, self, 1)

    def cumulative_sum(self):
        """Computes the cumulative sum of all the elements of an array"""
        return reduce(lambda ac, x: x + ac, self, 0)
    
    def __mul__(self, other):
        if isinstance(other, self.__class__):
            v = Vector()
            if len(self) > len(other):
                bgt = self
                smt = other
            else:
                bgt = other
                smt = self
            for i in range(len(bgt)):
                v.append(bgt[i] * smt[i] if i < len(smt) else bgt[i])
            return v
        elif isinstance(other, (int, float)):
            for i in range(len(self)):
                self[i] *= other
        else:
            raise TypeError(Vector.__gen_type_error_msg(other))
        
    def __add__(self, other):
        if not isinstance(other, Vector):
            raise TypeError(Vector.__gen_type_error_msg(other))
        elif len(other) != len(self):
            raise LenError('The vectors must have the same length.')
        a = Vector()
        for i in range(len(other)):
            a.append(other[i] + self[i])
        return a
    
    def __sub__(self, other):
        if not isinstance(other, Vector):
            raise TypeError(Vector.__gen_type_error_msg(other))
        elif len(other) != len(self):
            raise LenError('The vectors must have the same length.')
        a = Vector()
        for i in range(len(other)):
            a.append(other[i] - self[i])
        return a
    
    @staticmethod
    def ones(m, n = 1):
        """Return a n by m matrix filled with ones"""
        return [[1 for j in range(m)] for i in range(n)]

    @staticmethod
    def zeros(m, n = 1):
        """Return a n by m matrix filled with zeros"""
        return [[0 for j in range(m)] for i in range(n)]
    
    @staticmethod
    def __gen_type_error_msg(other):
        return f"Expected a numeric (float, int, Vector) type, got a {other.__class__.__name__} instance."
    
        
if __name__ == "__main__":
    v = Vector([1, 2, 3])
    w = Vector([4, 5, 6])
    t = v * w
    print(t)