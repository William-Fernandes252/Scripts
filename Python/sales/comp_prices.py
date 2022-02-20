def increase_price(value: float, increase: float) -> float:
    increased_price = value + (value * (increase / 100))  
    return increased_price

def reduce_price(value: float, reduction: float) -> float:
    reduced_price = value - (value * (reduction / 100)) 
    return reduced_price