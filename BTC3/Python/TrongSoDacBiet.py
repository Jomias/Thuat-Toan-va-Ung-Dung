def Sort(array, K):
    temp = []

    for i in range(K):
        temp.append([])

    for j in array:
        index = j % K
        temp[index].append(-j)

    temp = sorted(temp, reverse = True)

    cnt = 0
    for i in temp: 
        for j in range(len(i)):
            array[cnt] = -i[j]
            cnt += 1
    return array


array = [1, 2, 3, 4, 5]
print(Sort(array, 2))