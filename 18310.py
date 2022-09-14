from sys import stdin

N = int(input())
local = list(map(int, stdin.readline().split()))
local.sort()

print(local[(N-1)//2])