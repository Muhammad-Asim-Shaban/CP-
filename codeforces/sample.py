import math

def solve():
    K = int(input().strip())
    for _ in range(K):
        N, T, M = map(int, input().split())
        
        if N == 0:
            print(1 if T == 0 else 0)
            continue
        
        R = T - N * M
        if R < 0:
            print(0)
        else:
            # combinations with repetition
            result = math.comb(R + N - 1, N - 1)
            print(result)
