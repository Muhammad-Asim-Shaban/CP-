import sys

def solve():
    data = sys.stdin.buffer.read().strip().split()
    it = iter(data)
    T = int(next(it))
    out_lines = []
    for _ in range(T):
        
        N = int(next(it))
        e1 = int(next(it)); e2 = int(next(it))
        w1 = [0] + [int(next(it)) for _ in range(N)]
        w2 = [0] + [int(next(it)) for _ in range(N)]
        # s1: switch from lane1 -> lane2 after station j (j = 1..N-1)
        s1 = [0] + ([int(next(it)) for _ in range(N-1)] if N > 1 else [])
        # s2: switch from lane2 -> lane1 after station j (j = 1..N-1)
        s2 = [0] + ([int(next(it)) for _ in range(N-1)] if N > 1 else [])
        x1 = int(next(it)); x2 = int(next(it))

        # base (station 1)
        t1 = e1 + w1[1]
        t2 = e2 + w2[1]

        # stations 2..N
        for j in range(2, N+1):
            new_t1 = min(t1 + w1[j], t2 + s2[j-1] + w1[j])
            new_t2 = min(t2 + w2[j], t1 + s1[j-1] + w2[j])
            t1, t2 = new_t1, new_t2

        ans = min(t1 + x1, t2 + x2)
        out_lines.append(str(ans))

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()
