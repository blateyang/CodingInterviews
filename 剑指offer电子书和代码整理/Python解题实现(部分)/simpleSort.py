# coding:utf-8

def bubble_sort(arr):
    """冒泡排序(升序)"""
    if arr is None or len(arr) <= 1:
        return
    length = len(arr)
    for i in range(length-1): # len-1趟扫描
        for j in range(length-1-i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]


def select_sort(arr):
    """选择排序(升序)"""
    if arr is None or len(arr) <= 1:
        return
    length = len(arr)
    for i in range(length-1):
        maxIdx = length-1-i
        for j in range(length-1-i):
            if arr[j] > arr[maxIdx]:
                maxIdx = j
        arr[maxIdx], arr[length-1-i] = arr[length-1-i], arr[maxIdx]


def insert_sort(arr):
    """插入排序(升序)"""
    def compare_switch(arr, idx):
        """将传入的元素依次和其前的元素比较，小于则交换"""
        for i in range(idx-1, -1, -1):
            cur_idx = i+1
            if arr[cur_idx] < arr[i]:
                arr[cur_idx], arr[i] = arr[i], arr[cur_idx]
    if arr is None or len(arr) <= 1:
        return
    length = len(arr)
    for i in range(1, length):
        compare_switch(arr, i)

if __name__ == "__main__":
    arr = [4, 3, 2, 1]
#    bubble_sort(arr)
#    select_sort(arr)
    insert_sort(arr)
    print arr