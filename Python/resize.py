import os
from PIL import Image
from sys import argv, exit


def resizeimages(path, new_width, *options):
    if not os.path.isdir(path):
        raise NotADirectoryError(f'{path} is not a directory.')
    
    tag = '_pythonized'
    
    for root, dirs, files in os.walk(path):
        for file in files:
            file_path = os.path.join(root, file)
            file_name, extension = os.path.splitext(file)
            new_file = file_name + tag + extension
            new_file_path = os.path.join(root, new_file)
            
            if '-o' in options:
                os.remove(file_path)
            
            if os.path.isfile(new_file_path):
                print(f'File {new_file_path} already exists.')
                continue
            
            if tag in file_path:
                print(f'Image {file_path} already is resized.')
                continue
            
            if extension.lower() in '.jpg' and '-c' in options: 
                img = Image.open(file_path)
                width, height = img.size 
                new_height = round(new_width * height / width)
                resized_img = img.resize(
                    (new_width, new_height), 
                    Image.LANCZOS
                )
                
                resized_img.save(
                    new_file_path, 
                    optimize=True, 
                    quality=70,
                    exif=img.info['exif']
                )
                img.close()
                resized_img.close()
                
                print(f"Image {new_file_path} resized successfully.")
                os.remove(file_path)
                
                
if __name__ == '__main__':
    if len(argv) < 3:
        print(
            '',
            'This is a Python script to resize images with Pillow.',
            '',
            'Usage:',
            '\tresize.py dirpath width -(o, r)',
            'Arguments:',
            '\tdirpath\t- Absolute path to the folder to look for images to resize.',
            f'\twidth\t- New width to the image.',
            f'Options:',
            f'\tOverwrite (-o)\t- Delete the original images and save only the new ones.',
            f'\tCreate (-c)\t- Create new images and keep all the old ones.',
            '',
            sep='\n'
        )
        exit(1)
        
    options = ['-c', '-o']
        
    try:
        path = str(argv[1])
        width = int(argv[2])
    except:
        print('Invalid arguments.')
        exit(1)
        
    option = None
    if argv[3]:
        option = argv[3]
        if option not in options:
            raise ValueError('Invalid option.')

    resizeimages(path, width, option)
        
    