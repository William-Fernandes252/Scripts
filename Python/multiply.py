def multiply(x, y):
    """Multiply two integers using recursion

    Args:
        x (int): a integer value
        y (int): a integer value

    Returns:
        int: x * y
    """
    if y == 0 or x == 0:
        return 0
    if y < 0:    
        return multiply(x, y + 1) - x
    return x + multiply(x, y - 1)

print(multiply(-100, -3))