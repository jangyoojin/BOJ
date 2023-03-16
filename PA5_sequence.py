N = int(input())
S = [ 0 for _ in range(N+1)]
if N == 1: print(3)
elif N == 2: print(9)
elif N == 3: print(26)
else:
    S[1] = 3
    S[2] = 9
    S[3] = 26
    for i in range(4, N+1):
        S[i] = ((S[i-1] + S[i-2] + S[i-3]) *2)%1000000007
    print(S[N]%1000000007)