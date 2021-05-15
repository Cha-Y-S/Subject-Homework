from emit import *

def map_func(key, value):
    # code here!
    temp = value.split()
    for i in range(len(temp)):
        emit(temp[i],1)
    

def reduce_func(key, values):
    # code here!
    sum = len(values)
    emit(key, sum)
