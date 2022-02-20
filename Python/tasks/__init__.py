from itertools import count
from .operations import *


# Global variables
tasks_list = []
history = []
counter = count(start = 1)
options = {
    'c': 'Create new task',
    'r': 'Displays a list of all the tasks saved in the database',
    'u': 'Undo the last operation',
    'd': 'Delete a task',
    'w': 'Edit a task'
}