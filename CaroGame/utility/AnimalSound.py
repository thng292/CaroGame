def animalify(string: str, sound: str) -> str:
    tmp = str(string)
    lst = [_.strip() for _ in tmp.split()]
    print(lst)
    for word in lst:
        string = string.replace(word, sound, 1)
    return string


if __name__ == "__main__":
    sound = input("Enter a sound: ")
    f = open("input.txt", "r", encoding="utf-8")
    string = [_.split('=') for _ in f]
    f.close()
    for i in range(len(string)):
        string[i][1] = animalify(string[i][1], sound)

    f = open("output.txt", "w", encoding="utf-8")
    for i in range(len(string)):
        f.write(string[i][0] + '= ' + string[i][1])
    f.close()
