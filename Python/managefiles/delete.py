import os


def deletefiles(path, include = ''):
    """Delete files from the given absolute path that includes the given term to the new path.

    Args:
        path (str): The path of the directory to delete the files.
        include (str, optional): The substring to filter the files to delete. Default is ''.
    """
    
    filescount = 0
    for root, directives, files in os.walk(path):
        for file in files:
            if include in file:
                try:
                    filescount += 1
                    filepath = os.path.join(path, file)
                    os.remove(filepath)
                    print(f'File {file} copied successfully.')
                except PermissionError:
                    print('Access Denied.')
                except FileNotFoundError:
                    print('File Not Found.')
                except Exception as e:
                    print(f'Unknown error: {e}')
                    
    print(f'\n{filescount} file(s) moved.')