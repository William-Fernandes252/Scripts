from credentials.cpf import validate
    
while True:
    cpf = input("Enter a CPF to validate: ")
    # Regex to validate input
    print("Valid CPF." if validate(cpf) else "Invalid CPF.")