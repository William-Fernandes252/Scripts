from datetime import datetime
from calendar import monthrange
 
months_last_days = [
    monthrange(datetime.now().year, month)[1] for month in range(1, 13)
]
print(months_last_days)