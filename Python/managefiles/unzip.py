from zipfile import ZipFile
import os


def unzipfiles(path):
    """unzip all files at the zip specified in path.

    Args:
        path (str): The path to the directory to unzip.
    """
    
    dirname = os.path.basename(os.path.normpath(path))[:-4]
    with ZipFile(f'{dirname}.zip', 'r') as zip:
        zip.extractall(dirname)