import os
from managefiles.utils import formatsize


def findfiles(include = '', pathtolook = '/'):
    """List and details all files from the given absolute path that includes the given term.

    Args:
        include (str, optional): The term to search. Defaults to ''.
        pathtolook (str, optional): The absolute path to directory to search. Defaults to the system root '/'.
    """
    filescount = 0
    for root, directives, files in os.walk(pathtolook):
        for file in files:
            if include in file:
                try:
                    filescount += 1
                    abspath = os.path.join(root, file)
                    filename, extension = os.path.splitext(file)
                    size = os.path.getsize(file)
                    print(
                        '',
                        f'File fount: {file}',
                        f'Path: {abspath}',
                        f'Name: {filename}',
                        f'Extension: {extension}',
                        f'Size: {size}',
                        f'Formatted size: {formatsize(size)}',
                        sep='\n'
                    )
                except PermissionError:
                    print('Access Denied.')
                except FileNotFoundError:
                    print('File Not Found.')
                except Exception as e:
                    print(f'Unknown error: {e}')
                    
    print(f'\n{filescount} file(s) found.')