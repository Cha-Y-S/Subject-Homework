# Check korean sentence similarity
# input file : EUC-KR encoded 'corpus.txt' -- document
#               && EUC-KR encoded 'triVec.dat' -- preprocessed vector data
#   input sentence: 1 line of input file
#   output sentences: 2 sentence of input file that has most similarty
# Written by Cha Yoonsung, vaite714@gmail.com
# 20163162

import sys
import math

def loadTrigramVector(file):
    dic = {}

    f = open(file, 'r')
    line = f.readlines()

    for i in range(len(line)):
        temp = line[i].split()
        dic[temp[1]] = temp[0]
    
    f.close()

    return dic

def dot(vecA, vecB):
    sum = 0
    for i in range(0, len(vecA)):
        for j in range(0, len(vecB)):
            if vecA[i][0] == vecB[j][0]:
                sum += vecA[i][1] * vecB[j][1]
    return sum

def norm(v):
    sum = 1
    for i in range(0, len(v)):
        sum += (v[i][1] * v[i][1])
    return math.sqrt(sum)

def getCosSimilarity(vecA, vecB):
    return dot(vecA, vecB) / (norm(vecA) * norm(vecB))


def vectorizeSentence(s, mat):
    # result= [[id, freq], [id, freq], ...]
    result = []
    tSet = {}
    tSen = "^" + s + "$"
    tSen = tSen.replace(' ','_')    # blank 2 under bar
    for i in range(len(tSen) - 2):
        tTri = tSen[i:i+3]
        if tTri in mat:
            tSet[tTri] = tSet.get(tTri, 0) + 1
    
    for tri in tSet:
        tVec = [(int)(mat[tri]), tSet[tri]]
        result.append(tVec)

    result.sort(key=lambda x:x[0])

    return result


def printSimilarSentence(s, sens, mat):
    print("----- Input Sentence")
    print(" >> {sentence}{vector}\n".format(vector=vectorizeSentence(s, mat), sentence=s))
    print("----- Similar Sentence")
    print(" >> 1. {sentence}{vector}\n\tsimilarity:{sim}\n"
        .format(sentence = sens[1][0], vector=vectorizeSentence(sens[1][0], mat), sim = sens[1][1]))
    print(" >> 2. {sentence}{vector}\n\tsimilarity:{sim}\n"
        .format(sentence = sens[0][0], vector=vectorizeSentence(sens[0][0], mat), sim = sens[0][1]))

def main(argv, corpusFile, datFile):
    if len(argv) < 3:
        print("========== Invalid Command ==========\n")
        print("\tC> sentence-similarity.py corpus-EUC-KR.txt triVec.dat\n")
        print("corpus must be encoded by EUC-KR\n")
        print("triVec is preprocessed data by preprocessing.py\n")
        exit()

    vecMat = loadTrigramVector(datFile)

    f = open(corpusFile, 'r')

    line = f.readlines()

    lineLimit = 20

    # cLimit = len(line) # Maximum
    cLimit = int(len(line) / 10) # test1: Maximum / 10
    # cLimit = int(len(line) / 100) # test2: Maximum / 100
    # cLimit = int(len(line) / 1000) # test3: Maximum / 1000

    for i in range(lineLimit):
        simSentences = [["", 0], ["", 0]]
        sen1 = line[i]
        vec1 = vectorizeSentence(sen1, vecMat)
        for j in range(cLimit):
            # print("===== new j! =====")

            if i == j:
                continue
            sen2 = line[j]
            vec2 = vectorizeSentence(sen2, vecMat)
            
            temp = [sen2, getCosSimilarity(vec1, vec2)]

            simSentences.sort(key=lambda x:(float)(x[1]))

            if simSentences[0][1] < temp[1]:
                simSentences[0] = temp

            simSentences.sort(key=lambda x:(float)(x[1]))
        
        printSimilarSentence(sen1, simSentences, vecMat)

    return




if __name__ == "__main__":
    main(sys.argv, sys.argv[1], sys.argv[2])