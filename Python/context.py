from contextlib import contextmanager


# class File:
#     def __init__(self, path: str, mode: str):
#         print(f"Opening file at {path}")
#         self.file = open(path, mode)
        
#     def __enter__(self):
#         print("Returning file.")
        
#     def __exit__(self, exc_type, exc_val, exc_tb):
#         # print(exc_type)
#         # print(exc_tb)
#         # print(exc_val)
#         self.file.close()
#         print("Closing file.")
#         return True

        
# with File('abc.txt', 'w') as f:
#     f.write("Hello world!")


@contextmanager
def unfold(path: str, mode: str):
    try:
        print(f"Opening file at {path}.")
        file = open(path, mode)
        yield file
    finally:
        print("Closing file.")
        file.close()
        

with unfold('abc.txt', 'w') as f:
    f.write("Hello world!")