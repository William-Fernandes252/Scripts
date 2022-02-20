from prime import isPrime

def test_prime(n, expected):
    if isPrime(n) != expected:
        print(f"ERROR on isPrime({n}), expected {not expected}.")