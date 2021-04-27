from numpy import dot
from numpy.linalg import norm
import numpy as np

def cos_sim(A, B):
    return dot(A, B)/(norm(A)*norm(B))

def getTrigramSet(s):
    s = s.replace(' ', "_")
    trigramSet = {}
    for i in range(len(s) - 2):
        temp = ''.join(s[i:i+3])
        trigramSet[temp] = trigramSet.get(temp, 0) + 1
    return trigramSet

a = input("===== Enter First Sentence =====\n >> ")
b = input("\n===== Enter Second Sentence =====\n >> ")
print("")

aTri = getTrigramSet(a)
bTri = getTrigramSet(b)

totalTri = {}
totalTri.update(aTri)
totalTri.update(bTri)

totalList = list(totalTri.keys())
aVector = []
bVector = []

for i in range(len(totalList)):
    temp = totalList[i]
    if (temp in aTri):
        aVector.append(aTri[temp])
    else:
        aVector.append(0)
    if(temp in bTri):
        bVector.append(bTri[temp])
    else:
        bVector.append(0)

print(a, "\n", aVector)
print(b, "\n", bVector)

sim = cos_sim(aVector, bVector)
print("\nSIM(cos): ", sim)