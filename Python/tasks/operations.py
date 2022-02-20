from tasks.__init__ import options, tasks_list, history, counter


def query_task(task_id: int) -> dict:
    try:
        task = [task['id'] for task in tasks_list if task['id'] == task_id][0]
    except IndexError:
        task = {}
    finally:
        return task


def display_options():
    """Display the available options."""
    print('Options: ')
    for option, description in options.items():
        print(f'\t{option} - {description}')
    
    
def print_tasks():
    """Prints a list of all the tasks in the database."""
    for task in tasks_list:
        for id , description, time in task.items():
            print(f'Task {id}: {description} ({time})')
            
            
def create_task(description: str, time: str) -> None:
    """Receives a new task and add it to the database."""
    task = {'id': next(counter), 'description': description, 'time': time}
    tasks_list.append(task)
    history.append({'operation': 'c', 'task': task})
    
    
def delete_task(task_id: int) -> bool:
    """
    Deletes the task associated with the given ID and returns True.
    Return False if the task does not exist.
    """
    task_to_delete = query_task(task_id)
    if not task_to_delete:
        return False
    tasks_list.pop(task_id - 1)
    history.append({'operation': 'd', 'task': task_to_delete})
    return True


def update_task(task_id: int, new_description: str = '', new_time: str = '') -> bool:
    """
    Updates the task associated with the given ID with the updated 
    description and time.
    """
    task_to_update = query_task(task_id)
    before = {'description': task_to_update['description'], 'time': task_to_update['time']}
    
    if not task_to_update:
        return False
    
    if new_description:
        task_to_update['description'] = new_description   
    if new_time:
        task_to_update['time'] = new_time
        
    after = {'description': task_to_update['description'], 'time': task_to_update['time']}
    history.append({'operation': 'w', 'id': task_id, 'before': before, 'after': after})
    
    return True

    
def undo_operation() -> None:
    """
    Undo the last operation performed
    """
    log = history[len(history)-1]
    match log['operation']:
        case 'c':
            delete_task(log['task']['id'])
        case 'd':
            create_task(log['task']['description'], log['task']['time'])
        case 'w':
            update_task(log['id'], log['before']['description'], log['before']['time'])
    log['undone'] = True