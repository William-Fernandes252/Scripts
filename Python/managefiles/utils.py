def formatsize(size):
    """Given a file size in bytes, return a string representing the size of the file, with two decimal places, a maximum of 5 meaninfull digits and the prefix depending on it's size.

    Args:
        size (int): The file size in bytes.

    Returns:
        str: A formatted string representing the file size
    """
    
    base = 1024
    kilo = base
    mega = base ** 2
    giga = base ** 3
    tera = base ** 4
    peta = base ** 5
    
    if size < kilo:
        text = 'B'
    elif size < mega:
        size /= kilo
        text = 'K'
    elif size < giga:
        size /= mega
        text = 'M'
    elif size < tera:
        size /= giga
        text = 'G'
    elif size < peta:
        size /= tera
        text = 'T'
    else:
        size /= peta
        text = 'P'
        
    size = round(size, 2)
    return f'{size}{text}'