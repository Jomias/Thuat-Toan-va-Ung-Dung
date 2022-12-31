def sumOfDigit(n) :
    sum = 0;
    while (n > 0):
        sum += n % 10;
        n /= 10;
    return sum;
 
def sortedArr(arr, n) :
    vp = [];
    for i in range(n) :
        vp.append([sumOfDigit(arr[i]), arr[i]]);
    vp.sort()
    arr = []
    for i in range(len(vp)):
        arr.append(vp[i][1])
    return arr
 
if __name__ == "__main__" :
    arr = [13, 20, 20, 7, 4, 22, 25];
    n = len(arr);
    print(sortedArr(arr, n));
 