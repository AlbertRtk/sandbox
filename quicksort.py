import random


def quicksort(list):
	pivot_i = random.randint(0, len(list)-1)
	pivot = list[pivot_i]  # random pivot
	A = []  # elements smaller than pivot
	B = []  # elements larger than or equal to pivot
	for i, e in enumerate(list):
		if i == pivot_i:
			continue  # skip pivot
		if e < pivot:
			A.append(e)
		else:
			B.append(e)
	if len(A) > 1:
		A = quicksort(A)
	if len(B) > 1:
		B = quicksort(B)
	list = A + [pivot] + B
	return list


list = [4, 2, 6, 5, 8, 0, 1, 3, 2, 9, 7, -1]
print("\nUnsorted list: {}".format(list))
list = quicksort(list)
print("Sorted list: {} \n".format(list))
