n = int(input())
a = [int(input()) for i in range(n)]
a.sort()
print((a[n // 2] + a[(n - 1) // 2] + 1) // 2)