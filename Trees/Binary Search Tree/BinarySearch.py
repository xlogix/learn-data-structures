def binary_search(input_array, value):
    left = 0
    right = len(input_array)-1
    while left <= right:
        index = (left+right)//2
        middle = input_array[index]
        if middle < value:
            left = index+1
        elif middle > value:
            right = index-1
        else:
            return index
    return -1


test_list = [1, 3, 9, 11, 15, 19, 29]
test_val1 = 25
test_val2 = 15

print (binary_search(test_list, test_val1))
print (binary_search(test_list, test_val2))
