import re


def remove_puctuation(credential):
    """Remove non-digits from credential."""
    return re.sub(r'[^0-9]', '', credential)


def check_sequence(credential):
    """Checks if the given credential consists of a sequence of equal digits."""
    return credential[0] * len(credential) == credential