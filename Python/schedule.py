import tasks
from tasks.utils.input_check import get_id
    
def main():
    while True:
        while True:
            tasks.display_options()
            operation = input('Enter a command to execute: ').lower()
            if operation in tasks.options.keys():
                break
            print('Invalid option.')
        match operation:
            case 'c':
                description = input('Description: ')
                time = input('Time (dd:hh:mm): ')
                tasks.create_task(description, time)
            case 'r':
                tasks.print_tasks()
            case 'u':
                tasks.undo_operation()
            case 'd':
                task_id = get_id()
                if not tasks.delete_task(task_id):
                    print(f"Operation failed: task with id {task_id} not found.")
            case 'w':
                task_id = get_id()
                new_description = input('Enter the new description (leave blank to skip): ')
                new_time = input('Enter the new time (leave blank to skip): ')
                if not tasks.update_task(task_id, new_description, new_time):
                    print(f"Operation failed: task with id {task_id} not found.")
            
        
if __name__ == '__main__':
    main()