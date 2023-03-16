from sys import stdin

def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def partition(arr, start, end):
    pivot = arr[start][3]
    i = start + 1
    j = end
    while i < j:
        while arr[i][3] < pivot and i < end: i += 1
        while arr[j][3] > pivot and j > start + 1: j -= 1
        if i < j: swap(arr, i, j)
    swap(arr, start, j)
    return arr, j
    

def quickSort_upward(arr, start, end):
    if start < end:
        arr, sorted_index = partition(arr, start, end)
        quickSort_upward(arr, start, sorted_index - 1)
        quickSort_upward(arr, sorted_index+1, end)
    return arr

def quickSort_downward(arr, start, end):
    quickSort_upward(arr, start, end)
    for i in range(len(arr)//2):
        swap(arr, i, end-i)
    return arr



T = int(input())
for _ in range(T):
    N = int(input())
    XPositive_points = [] #[x, y, dist]
    XNegative_points = []
    XPositive_count = 0
    XNegative_count = 0
    for _ in range(N):
        x, y = map(int, stdin.readline().split())
        dist = (x**2 + y**2)
        if y >= 0: cos = y**2 / dist
        else: cos = -y**2 / dist
        if x >= 0:
            XPositive_points.append([x, y, dist, cos])
            XPositive_count += 1
        else:
            XNegative_points.append([x, y, dist, cos])
            XNegative_count += 1
    
    result_left = quickSort_downward(XPositive_points, 0, XPositive_count-1)
    result_right = quickSort_upward(XNegative_points, 0 , XNegative_count - 1)

    for x, y, dist, cos in result_left:
        print(x, y)
    for x, y, dist, cos in result_right:
        print(x, y)
    print("\n")