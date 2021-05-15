# Count word for highest frequency 1,000 word about wikisent2.txt(from Kaggle)
# input file: wikisent2.txt -- document(from Kaggle)
# output file: out.txt -- Words with the top 1000 frequencies
# 
# Written by Cha Yoonsung, vaite714@gmail.com
# Kookmin.Univ Software 20163162

import sys
from tqdm import tqdm

def storeCountedWord(wSet):
    w = open("out.txt", 'w', encoding='utf8')

    for i in range(1000):
        if(i > len(wSet) - 1):
            break
        word = wSet[i][0]
        freq = (int)(wSet[i][1])

        data = "{w}\t{f}\n".format(w=word, f=freq)
        w.write(data)
    
    w.close()

def getWordSet(l):
    wSet = {}
    for i in tqdm(range(len(l))):
        temp = l[i].split()
        for j in range(len(temp)):
            word = ''.join(temp[j])
            wSet[word] = wSet.get(word, 0) + 1
    
    wSet = sorted(wSet.items(), reverse=True, key=lambda item:item[1])
    return wSet


def main(argv):
    if len(argv) != 2:
        print("========== Invalid Command ==========\n")
        print("\t C > wordcount.py wikisent.txt\n")
        exit()
    
    f = open(argv[1], 'r', encoding='utf8')

    line = f.readlines()

    wordSet = []

    wordSet = getWordSet(line)

    storeCountedWord(wordSet)

    f.close()


if __name__ == "__main__":
    main(sys.argv)