n = int(input())
s = sum(int(input()) for i in range(n))
print(s, '%.5f' % (s / n))