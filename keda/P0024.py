n, k = map(int, input().split())
nk = n // k
sk = (1 + nk) * nk // 2 * k
nn = n - nk
sn = n * (n + 1) // 2 - sk
print('%.1f %.1f' % (sk / nk, sn / nn))
