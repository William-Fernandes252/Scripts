import re


def get_id() -> int:
    while True:
        try:
            task_id = int(input("Enter the task ID: "))
        except ValueError:
            print("Error: invalid ID.")
        else:
            break
    return task_id