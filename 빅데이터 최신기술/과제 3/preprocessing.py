# Preprocessing data for checking korean sentence similarity
# input file : EUC-KR encoded 'out.txt' -- trigram's frequency using wordcount
#   1. Check trigram's frequency
#   2. Remove trigram that has under 50 frequency
#   3. Remove trigram that has no korean syllable
#   4. Register remainder tirgram with unique id
# Written by Cha Yoonsung, vaite714@gmail.com
# 20163162
import sys
import re

hangul = re.compile('[^ ㄱ-ㅣ가-힣]+')

def loadWordCount(file):
    triVec = {}

    f = open(file, 'r')
    wf = open("triVec.txt", 'w')

    line = f.readlines()
    k = 1
    for i in range(len(line)):
        temp = line[i].split()
        if int(temp[0]) > 50:
            try:
                fSyl = hangul.match(temp[1][0]) # First Syllable
                sSyl = hangul.match(temp[1][1]) # Second Syllable
                tSyl = hangul.match(temp[1][2]) # Third Syllable
                if (not fSyl) or (not sSyl) or (not tSyl):
                    triVec[temp[1]] = k
                    data = '{id}\t{trigram}\n'.format(id=k, trigram=temp[1])
                    wf.write(data)
                    k = k + 1
            except:
                continue
    
    f.close()
    wf.close()
    
    return triVec

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("========== Invalid Command ==========")
        print("C> python preprocessing.py out.txt")
        print("out.txt is output of wordcount.exe(trigram.txt)")
        exit()

    triCount = sys.argv[1]

    dic = loadWordCount(triCount)

    print(dic)