# import sales.comp_prices
from sales.comp_prices import increase_price, reduce_price
from sales.format.price import brl

initial_price = 49.90
price_icreased = increase_price(initial_price, 15)
print(brl(price_icreased))