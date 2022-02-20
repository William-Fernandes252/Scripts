import bank
from bank.accounts import SavingsAcc, CurrentAcc
from bank.users import PF
from random import randint

print('\nBanco do Brasil CLI\n-------------------')
print('\nRegister yourself.')
name = input('\nName: ')
age = int(input('Your age: '))
access = input('Your access for the mobile app (a 4-digit number): ')
cpf = input('Your CPF: ')
*city, state = input('Your adress (city followed by state symbol): ').split()
' '.join(city)

user = PF(name, age, access, cpf)
user.add_address(city, state)
bank.bb.add_client(user)

print('Create an account\n\t1 for a current account\n\t2 for a savings account')
while True:
    answer = input()
    if answer != '1' and answer != 'n':
        print('Please enter a valid option.')
        continue
    else:
        break
    
account = '4567328'
password = input('Enter your password (6 digits): ')
initial_balance = input('Make a initial deposit (leave blank to skip): ')
initial_balance = 0 if initial_balance == '' else float(initial_balance)

if answer == '1':
    acc = SavingsAcc(bank.bb, bank.maua_sp.agency_number, account, password, cpf, initial_balance)
elif answer == '2':
    acc = CurrentAcc(bank.bb, bank.maua_sp.agency_number, account, password, cpf, initial_balance)
user.add_account(acc)
     
print(f'\nAccount {account}:')
print("----------------")
while True:
    print('\nOptions:\n\t1 - Deposit\n\t2 - Withdraw\n\t3 - Details\n\t0 - Exit\n')
    while True:
        option = input('Enter a option: ')
        if option not in bank.options:
            print("Please enter a valid option.")
            continue
        else:
            break
    if option == '1':
        value = input('Enter a value to deposit: ')
        [acc.deposit(value) for acc in bank.maua_sp.accounts if acc.account_number == account]
    elif option == '2':
        value = input('Enter a value to withdraw: ')
        pwd = input('Enter your password: ')
        [acc.withdraw(value, pwd, user) for acc in bank.bb.accounts if acc.account_number == account]
    elif option == '3':
        [acc.details() for acc in bank.maua_sp.accounts if acc.account_number == account]
    elif option == '0':
        break