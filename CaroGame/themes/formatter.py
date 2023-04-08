import sys
import functools

help = '''
    This script is used to format the language files.
    Usage:
        --help  :   Print this message
        --create:   Create a new language file template.
        file names: Format files
            Ex: python3 formatter.py en.txt
'''

key_word_list = ['TITLE_TEXT_COLOR', 'TEXT_COLOR', 'TEXT_HIGHLIGHT_COLOR', 'BORDER_COLOR', 'CONSOLE_COLOR', 'CONSOLE_HIGHLIGHT_COLOR', 'PLAYER_ONE_COLOR', 'PLAYER_TWO_COLOR', 'PLAYER_ONE_HIGHLIGHT_COLOR', 'PLAYER_TWO_HIGHLIGHT_COLOR', 'AI_EASY_COLOR', 'AI_NORMAL_COLOR', 'AI_HARD_COLOR', 'RESULT_TEXT_COLOR', 'WIN_HIGHLIGHT_COLOR', 'HINT_COLOR', 'WARNING_COLOR', 'GHOST_MOVE_COLOR', 'CURSOR_COLOR']

def basiccmp(str1, str2):
    if str1 == str2:
        return 0
    else:
        return 1 if str1 > str2 else -1

def sortfunc(item1, item2):
    if item1[0] == '[' and item2[0] == '[' :
        return basiccmp(item1, item2)
    elif item1[0] == '[' :
        return -1
    elif item2[0] == '[' :
        return 1
    else :
        return basiccmp(item1, item2)
def formatter():
    files_formatted = []
    for file in sys.argv[1:]:
        try :
            f = open(file, encoding='utf-8', mode='r')
        except:
            continue

        tmp = [_.split(sep='=') for _ in filter(lambda x : len(x) > 0, [line.strip() for line in f])] 
        f.close()
        for i in range(len(tmp)):
            tmp[i] = [_.strip() for _ in tmp[i]]
        
        mmax = (max([len(_[0]) for _ in tmp]) // 4) * 4 + 4
        check_list = [_ for _ in key_word_list]
        for index, i in enumerate(tmp) :
            if i[0] not in key_word_list:
                print(f"Warning:\nFile: {file}, at line: {index+1}, label: {i[0]} does not exist in the game.")
                continue
            if i[0] in check_list:
                check_list.remove(i[0])
            else:
                print(f"Warning:\nFile: {file}, at line: {index+1}, label: {i[0]} appeared more than once.")

        if (len(check_list)) :
            print("Warning:\nFile: {file}, you are missing these title:")
            for i in check_list:
                print('    ' + i)
            print()

        f = open(file, mode='w', encoding='utf-8')
        f.writelines(sorted(["=".join([_[0].ljust(mmax), "    " + _[1]]) + '\n' for _ in tmp], key=functools.cmp_to_key(sortfunc)))
        f.close()
        files_formatted.append(file)

    print(f"Formatted successful: {', '.join(files_formatted)}")

if __name__ == '__main__':
    if '--create' in sys.argv:
        filename = input("Enter the file name: ")
        f = open(filename, mode='w', encoding='utf-8')
        mmax = (max([len(_) for _ in key_word_list]) // 4) * 4 + 4
        f.write('=\n'.join([_.ljust(mmax) for _ in key_word_list]))
    elif '--help' in sys.argv or len(sys.argv) == 1:
        print(help)
    else:
        formatter()
