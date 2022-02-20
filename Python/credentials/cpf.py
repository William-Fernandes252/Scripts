from random import randint
from credentials.utils import remove_puctuation, check_sequence

def format_cpf(cpf):
    cpf_numbers = remove_puctuation(cpf)
    return f'{cpf_numbers[0:3]}.{cpf_numbers[3:6]}.{cpf_numbers[6:9]}-{cpf_numbers[9:]}'

def generate(n = 1):
    """Generates valid cpfs with a random number generator 

    Returns:
        List of n valid cpfs
    """
        
    reverse = 10
    sum = 0
    cpfs = []
    
    for cpf in range(n):
        validated_cpf = str(randint(100000000, 999999999))
        for i in range(19):
            if i > 8:
                i -= 9
            sum += int(validated_cpf[i]) * reverse
            reverse -= 1

            if reverse < 2:
                reverse = 11
                d = 11 - (sum % 11)
                d = 0 if d > 9 else d
                sum = 0
                validated_cpf += str(d)
            
        cpfs.append(format_cpf(validated_cpf))
        
    return cpfs if len(cpfs) > 1 else cpfs[0]


def validate(cpf):
    """Validates a CPF through it's digits

    Args:
        cpf (String)
    """
    
    if check_sequence(cpf):
        return False
    
    try:
        formatted = remove_puctuation(cpf)
        non_digits = formatted[:-2]
        digits = formatted[9:]
        
        first_products_sum = 0
        for i, r in enumerate(range(10, 1, -1)):
            first_products_sum += int(non_digits[i]) * r
        first_digit = 11 - (first_products_sum % 11)
        first_digit = 0 if first_digit > 9 else first_digit
            
        second_products_sum = 0
        for i, r in enumerate(range(11, 2, -1)):
            second_products_sum += int(non_digits[i]) * r
        second_products_sum += first_digit * 2
        second_digit = 11 - (second_products_sum % 11)
    except:
        return False
    
    return first_digit == int(digits[0]) and second_digit == int(digits[1])


def validate2(cpf):
    """Validates a CPF through it's digits

    Args:
        cpf (String)
    """
    
    if check_sequence(cpf):
        return False
    
    try:
        formatted = remove_puctuation(cpf)
        non_digits = formatted[:-2]
        validated_cpf = non_digits
        
        reverse = 10
        sum = 0
        
        for i in range(19):
            if i > 8:
                i -= 9
            sum += int(validated_cpf[i]) * reverse
            reverse -= 1

            if reverse < 2:
                reverse = 11
                d = 11 - (sum % 11)
                d = 0 if d > 9 else d
                sum = 0
                validated_cpf += str(d)
    except:
        return False
            
    return validated_cpf == cpf