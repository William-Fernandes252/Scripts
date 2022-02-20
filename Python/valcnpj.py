from credentials.cnpj import validate

while True:
    cnpj = input("Enter a CNPJ to validate: ")
    # Regex to validate input
    print("Valid CNPJ." if validate(cnpj) else "Invalid CNPJ.")