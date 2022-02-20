from zipfile import ZipFile
import os


def zipfiles(path):
    """Zip all files at the directory specified in path.

    Args:
        path (str): The path to the directory to zip files.
    """
    
    filescount = 0
    dirname = os.path.basename(os.path.normpath(path))
    with ZipFile(f'{dirname}.zip', 'w') as zip:
        for file in os.listdir(path):
            filescount += 1
            abspath = os.path.join(path, file)
            zip.write(abspath, file)
            
    print(f'{filescount} file(s) zipped.')