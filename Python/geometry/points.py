from geometry.vectors import Vector


class Point():
    def __init__(self, x = 0, y = 0, z = 0):
        self.x = x
        self.y = y
        self.z = z
        
    def __repr__(self):
        return f'<class: Point({self.x}, {self.y}, {self.z})>'
    
    def __sub__(self, other):
        if not isinstance(other, self.__class__):
            raise TypeError(f"Expected Point instance, got {other.__class__.__name__}.")
        return Vector([self.x - other.x, self.y - other.y, self.z - other.z])
    

if __name__ == '__main__':
    p1 = Point(2, 5)
    p2 = Point(3, 10)
    print(p2 - p1)
    print(p1)