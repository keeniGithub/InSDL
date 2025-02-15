import os

def disk_letter():
    current_file_path = os.path.abspath(__file__)
    letter = current_file_path[0:2]
    return letter