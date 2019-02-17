list = [4, 2, 6, 8, 5, 0, 1, 3, 9, 7]

print("\nUnsorted list: {}".format(list))

for i in range(len(list)-1):
    m = list.index(min(list[i:]))  # finding the index of minimum
    list[i], list[m] = list[m], list[i]

print("Sorted list: {} \n".format(list))
