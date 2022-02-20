from datetime import datetime, timedelta
from locale import setlocale, LC_ALL
from calendar import mdays

setlocale(LC_ALL, 'pt_BR.utf-8')

date = datetime(2021, 2, 10, 11, 45, 20)
print('Today: ',date.strftime('%d/%m/%Y %H:%M:%S'))
month = int(date.strftime('%m'))

yesterday = datetime.strptime('20/04/2019', '%d/%m/%Y')

print('Yesterday: ', yesterday)

print('Date timestamp: ', date.timestamp())
print('Today timestamp: ', date.timestamp())
print('From timestamp: ', 1612968320.0)

pastday = datetime.strptime('20/04/1987 20:00:00', '%d/%m/%Y %H:%M:%S')
print('Past day: ', pastday.strftime('%d/%m/%Y %H:%M:%S'))
pastday = pastday + timedelta(days=10)
print('Past day plus 10 days: ', pastday.strftime('%d/%m/%Y %H:%M:%S'))

d1 = datetime.strptime('20/04/1982 20:00:00', '%d/%m/%Y %H:%M:%S')
d2 = datetime.strptime('25/04/1982 22:33:00', '%d/%m/%Y %H:%M:%S')

dif = d2 - d1
print('Timedelta: ', dif)

formatted = date.strftime('%A, %d de %B de %Y.')
print('In text:', formatted)

print('Last day of the current month:', mdays[month])