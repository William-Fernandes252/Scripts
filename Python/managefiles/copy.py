import os
import shutil


def copyfiles(oldpath, newpath, include = ''):
    """Copy files from the given absolute path that includes the given term to the new path.

    Args:
        oldpath (str): The path to the directory to copy files from.
        newpath (str): The path of the directory to copy the files.
        include (str, optional): The substring to filter the files to copy. Default is ''.
    """
    
    try:
        os.mkdir(newpath)
    except FileExistsError:
        print(f'Directory at {newpath} already exists.')
        return 
    
    filescount = 0
    for root, directives, files in os.walk(oldpath):
        for file in files:
            if include in file:
                try:
                    filescount += 1
                    oldfilepath = os.path.join(root, file)
                    newfilepath = os.path.join(newpath, file)
                    shutil.copy(oldfilepath, newfilepath)
                    print(f'File {file} copied successfully.')
                except PermissionError:
                    print('Access Denied.')
                except FileNotFoundError:
                    print('File Not Found.')
                except Exception as e:
                    print(f'Unknown error: {e}')
                    
    print(f'\n{filescount} file(s) copied.')