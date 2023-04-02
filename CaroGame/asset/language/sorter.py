import sys
import functools

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
        print("Can't open file "+file)
        continue

    tmp = [line.strip() for line in f]
    tmp = filter(lambda x : len(x) > 0, tmp)
    tmp = sorted(tmp, key=functools.cmp_to_key(sortfunc))
    tmp = [_.split(sep='=') for _ in tmp] 
    f.close()
    for i in range(len(tmp)):
        tmp[i] = [_.strip() for _ in tmp[i]]
    mmax = max([len(_[0]) for _ in tmp])
    mmax = (mmax // 4) * 4 + 4
    tt = {}
    for i in tmp :
        tt[i[0]] = i[1]
    print(tt)
    tmp = [[key, tt[key]] for key in tt]
    tmp = ["=".join([_[0].ljust(mmax), "    " + _[1]]) + '\n' for _ in tmp]
    f = open(file, mode='w', encoding='utf-8')
    f.writelines(tmp)
    f.close()
