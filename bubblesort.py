list = [7, 4, 1, 3, 6, 9, 0, 8, 2, 5]
swapped = True  # checking if in last iteration any elements were swapped

print("\nUnsorted list: {}".format(list))

while swapped == True:
    swapped = False  # assuming that there will be no swapping
    for i, v in enumerate(list[:-1]):
        if list[i] > list[i+1]:
            list[i], list[i+1] = list[i+1], list[i]
            swapped = True  # swapping occured

print("Sorted list: {}\n".format(list))