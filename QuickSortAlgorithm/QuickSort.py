def quickSort(arr):
    length = len(arr)
    if length < 2:
        return arr
    pivot = arr[int(length / 2)]
    equal = [i for i in arr if i ==pivot]
    less = [i for i in arr if i <pivot]
    greater = [i for i in arr if i > pivot]
    return quickSort(less) + equal + quickSort(greater)


print(quickSort([1, 5, 6, 86, 3, 3, 6, 9, 3, 65, 6]))
