import csv

with open('static/clients.csv', 'r') as file:
    data = [client for client in csv.DictReader(file)]
    # next(data)

    # for client in data:
    #     print(client['Name'], client['Surname'], client['E-mail'], client['Phone'])
    
with open('static/customers.csv', 'w') as file:
    writer = csv.writer(
        file,
        delimiter=',',
        quotechar='"',
        quoting=csv.QUOTE_ALL,
        lineterminator='\n'
    )
    
    keys = data[0].keys()
    keys = list(keys)
    writer.writerow(keys)
    
    for customer in data:
        writer.writerow(
            [
                customer['Name'],
                customer['Surname'],
                customer['E-mail'],
                customer['Phone']
            ]
        )