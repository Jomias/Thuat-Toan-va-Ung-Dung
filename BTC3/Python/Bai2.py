def FindAnswer(arr):
    size = len(arr)
    count = [0] * (max(arr) + 1)
    output = [0] * size
    for i in arr:
        count[i] += 1
    mode = count.index(max(count))
    for i in range(1, len(count)):
        count[i] += count[i - 1]
    for i in range(size):
        output[count[arr[i]] - 1] = arr[i]
        count[arr[i]] -= 1
    print(output)
    if size % 2 == 1:   return mode, output[(size + 1) // 2]
    return mode, (output[size // 2 - 1] + output[size // 2]) / 2

if __name__ == '__main__':
    arr = [1, 4, 1, 2, 7, 1, 2, 5, 3, 6]
    mode, median = FindAnswer(arr)
    print(f"Mot: {mode}")
    print(f"Trung Vi: {median}")