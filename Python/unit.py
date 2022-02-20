import unittest
from prime import isPrime

class Tests(unittest.TestCase):
    
    def test_1(self):
        """Check that 1 is not prime."""
        self.assertFalse(isPrime(1))

    def test_2(self):
        """Check that 2 is prime."""
        self.assertTrue(isPrime(2))

    def test_3(self):
        """Check that 3 is prime."""
        self.assertTrue(isPrime(3))
        
    def test_8(self):
        """Check that 8 is not prime."""
        self.assertFalse(isPrime(8))
        
    def test_25(self):
        """Check that 25 is not prime."""
        self.assertFalse(isPrime(25))
        
if __name__ == '__main__':
    unittest.main()