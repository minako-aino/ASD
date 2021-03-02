from random import random
import time

def fill_in(size):
    list = []
    while size != len(list):
        elem = int(random() * (size + 1))
        list.append(elem)
    return list

def sort_ins(list):
    global copies, comparisons
    copies = 0
    comparisons = 0
    for i in range(len(list)):
        copies += 1
        buffer = list[i]
        j = i - 1

        while j >= 0 and list[j] > buffer:
            comparisons += 1
            copies += 1
            list[j+1] = list[j]
            j -= 1
        comparisons += 1
        
        copies += 1
        list[j+1] = buffer
        
    return list


quantities = [100, 1000, 10000]
for N in quantities: 
    list = fill_in(N)
    start_time = time.time() 
    sort_ins(list)
    print(f"{round((time.time() - start_time), 5)} s")
    print(copies, comparisons)
    print(list)
