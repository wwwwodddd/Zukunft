import sys
n = int(input())
a = list(map(int, sys.stdin.read().split()[1:]))
print(max(a))
print(min(a))
