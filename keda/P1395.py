n = int(input())
a = list(map(int, input().split()))
s = sum(a)
t = sum(i * i for i in a)
print((s * s - t) // 2)