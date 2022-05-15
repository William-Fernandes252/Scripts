def list_xor(n: int, x: list, y: list) -> bool:
    return (n in x and n not in y) or (n in y and n not in x)


def main():
    assert list_xor(1, [1, 2, 3], [2, 3, 4])


if __name__ == '__main__':
    main()
