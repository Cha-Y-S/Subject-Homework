# Check korean sentence similarity
# input file : EUC-KR encoded 'corpus.txt' -- document
#               && EUC-KR encoded 'triVec.dat' -- preprocessed vector data
#   input sentence: 1 line of input file
#   output sentences: 2 sentence of input file that has most similarty
# Written by Cha Yoonsung, vaite714@gmail.com
# 20163162

import sys

def loadTrigramVector(file):
    dic = {}

    f = open(file, 'r')
    line = f.readlines()

    for i in range(len(line)):
        temp = line[i].split()
        dic[temp[1]] = temp[0]
    
    return dic
    

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("========== Invalid Command ==========")
        print("C> sentence-similarity.py corpus-EUC-KR.txt out.txt")
        print("corpus must be encoded by EUC-KR")
        print("out.txt is output of wordcount.exe(trigram.txt)")
        exit()

    corpus = sys.argv[1]
    triVec = sys.argv[2]

    vecMat = loadTrigramVector(triVec)

    print(vecMat)