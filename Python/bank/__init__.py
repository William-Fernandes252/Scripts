from bank.agency import Agency, Bank 

bb = Bank('Banco do Brasil')
maua_sp = Agency('54678')
bb.add_agency(maua_sp)

options = ['0', '1', '2', '3']