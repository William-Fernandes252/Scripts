from credentials.utils import remove_puctuation, check_sequence
from random import randint


def format_cnpj(cnpj):
    cnpj_numbers = remove_puctuation(cnpj)
    return f'{cnpj_numbers[:2]}.{cnpj_numbers[2:5]}.{cnpj_numbers[5:8]}/{cnpj_numbers[8:12]}-{cnpj_numbers[12:]}'


def first_digit_validator():
    """Generates the operators to compute the first digit of a CNPJ

    Yields:
        int: operator to compute the first digit of a CNPJ
    """
    operators = (5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2)
    for i in operators:
        yield i
            
            
def second_digit_validator():
    """Generates the operators to compute the second digit of a CNPJ

    Yields:
        int: operator to compute the second digit of a CNPJ
    """
    operators = (6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2)
    for i in operators:
        yield i
        
        
def compute_digit(validator, non_digits):
    """Validate a digit of a CNPF with the given validator and the non-digits provided

    Args:
        validator (generator): A generator corresponding to the digit to be validated
        non_digits ([type]): The numbers before the digit

    Returns:
        str: The validated digit
    """
    sum = 0
    for nd in non_digits:
        sum += int(nd) * next(validator)
    d = 11 - (sum % 11)
    return str(0 if d > 9 else d)


def validate(cnpj):
    """Checks if the given CNPJ is valid.

    Args:
        cnpj (str): A CNPJ to validate.

    Returns:
        bool: Validation of the given CNPJ
    """
    
    if check_sequence(cnpj):
        return False
    
    try:
        formatted = remove_puctuation(cnpj)
        validated_cnpj = formatted[:-2]
        validated_cnpj += compute_digit(first_digit_validator(), validated_cnpj)
        validated_cnpj += compute_digit(second_digit_validator(), validated_cnpj)
    except:
        return False
       
    return validated_cnpj == cnpj


def generate(n = 1):
    """Generates valid cnpjs with a random number generator 

    Returns:
        List of n valid cnpjs
    """
    cnpjs = []
    for i in range(n):
        validated_cnpj = str(randint(100000000000, 999999999999))
        validated_cnpj += compute_digit(first_digit_validator(), validated_cnpj)
        validated_cnpj += compute_digit(second_digit_validator(), validated_cnpj)
        cnpjs.append(format_cnpj(validated_cnpj))
    return cnpjs if len(cnpjs) > 1 else cnpjs[0]
