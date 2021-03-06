#!/usr/bin/env python3

import os

folder_name = '_bib'

dirs = [
    'db',
    'devops',
    'distsys',
    'general',
    'lang',
]


def merge_folder(folder):
    files = []
    for file in os.listdir(folder):
        if file.endswith(".bib"):
            files.append(os.path.join(folder, file))
    merged = ''
    for file in files:
        with open(file) as f:
            prefix = '\n% ==== file: ' + file + ' ====\n'
            content = f.read()
            suffix = '\n% ==== /file: ' + file + ' ====\n'
            merged += prefix + content + suffix
    return merged


def main():
    # chdir to project root
    file_dir = os.path.dirname(os.path.realpath(__file__))
    project_root = os.path.normpath(file_dir + os.sep + '..')
    os.chdir(project_root)
    # print(project_root)
    merged = '% auto generated by ' + os.path.realpath(__file__) + ' DO NOT EDIT\n'
    # TODO: add git revision, generated date etc.
    for folder in dirs:
        merged += merge_folder(os.path.join(folder, folder_name))
    with open('merged.bib', 'w') as f:
        f.write(merged)


if __name__ == '__main__':
    main()
