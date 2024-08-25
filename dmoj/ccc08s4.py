for _ in range(int(input())):
    h = []
    for _ in range(4):
        h.append(int(input()))
    f = [set() for i in range(16)]
    for i in range(4):
        f[1 << i].add(h[i])
    for i in range(1, 16):
        for j in range(16):
            if (i & j) == j:
                for x in f[j]:
                    for y in f[i - j]:
                        f[i].add(x + y)
                        f[i].add(x - y)
                        f[i].add(x * y)
                        if y != 0 and x % y == 0:
                            f[i].add(x // y)
    print(max(i for i in f[15] if i <= 24))
