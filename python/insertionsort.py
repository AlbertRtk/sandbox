list = [4, 2, 6, 5, 8, 0, 1, 3, 2, 9, 7]

print("\nUnsorted list: {}".format(list))

for i, e in enumerate(list[1:], 1):
    for ii, ee in enumerate(list[:i]):
        if e<=ee:
            list = list[:ii] + [e] + list[ii:i] + list[i+1:]
            break
			
print("Sorted list: {} \n".format(list))
