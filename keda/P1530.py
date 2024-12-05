import sys
a = sys.stdin.read().split()
n = int(a[0])
s = set(map(int, a[1 : n + 1]))
t = set(map(int, a[n + 1 : ]))
print(min(s & t))