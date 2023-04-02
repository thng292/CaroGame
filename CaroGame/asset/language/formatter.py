import sys
import functools

'''
    This script is used to format the language files.
'''

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
    check_dup_dict = {}
    fail = False
    for index, i in enumerate(tmp) :
        if (i[0] in check_dup_dict) :
            fail = True
            print(f"Error in file: {file}, at line: {index+1}, label: {i[0]}. GO FIX IT NOW")
        check_dup_dict[i[0]] = i[1]
    if not fail:
        f = open(file, mode='w', encoding='utf-8')
        f.writelines(sorted(["=".join([_[0].ljust(mmax), "    " + _[1]]) + '\n' for _ in tmp], key=functools.cmp_to_key(sortfunc)))
        f.close()
