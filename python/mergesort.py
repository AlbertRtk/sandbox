def mergesort(list):
    l =  len(list)
    if l <= 1:
        return list
    else:
        i = l // 2
        A = mergesort(list[:i])
        B = mergesort(list[i:])
        la = len(A)
        lb = len(B)
        i, j = 0, 0
        list = []
        while i < la and j < lb:
            if A[i] <= B[j]:
                list.append(A[i])
                i += 1
            else:
                list.append(B[j])
                j += 1
        if i == la:
            list += (B[j:])
        else:
            list += (A[i:])
        return list


list = [4, 2, 6, 5, 8, 0, 1, 3, 2, 9, 7, -1]
print("\nUnsorted list: {}".format(list))
list = mergesort(list)		
print("Sorted list: {} \n".format(list))
