from random import random
import time

def fill_in(size):
    list = []
    while size != len(list):
        elem = int(random() * (size + 1))
        list.append(elem)
    return list

def partition(nums, low, high): 
    global comparisons, copies
    # pivot element is in the middle
    pivot = nums[(low + high) // 2]
    i = low - 1
    j = high + 1
    while True:
        i += 1
        while nums[i] < pivot:
            i += 1
            comparisons += 1
        j -= 1
        while nums[j] > pivot:
            j -= 1
            comparisons += 1
        if i >= j:
            return j
        
        # if the left elemnt greater, than right, swap them
        copies += 2
        nums[i], nums[j] = nums[j], nums[i]

def quick_sort(nums):
    def _quick_sort(items, low, high):
        global comparisons, copies
        if low < high:
            comparisons += 1
            split_index = partition(items, low, high)
            _quick_sort(items, low, split_index)
            _quick_sort(items, split_index + 1, high)

    _quick_sort(nums, 0, len(nums) - 1)

list = fill_in(100000)
#print(list)

copies = 0
comparisons = 0 
start_time = time.time() 
quick_sort(list)
print(f"{(time.time() - start_time)} s")
print(copies, comparisons) 
