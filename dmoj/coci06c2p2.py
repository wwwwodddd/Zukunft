a = sorted(list(map(int, input().split())))
b = [a[ord(i) - 65] for i in input()]
print(*b)