n, k = map(int, input().split())
a = [int(input()) for i in range(n)]
z = 0
for i in range(len(a)):
	z += min(a[i], a[k] - (i > k))
print(z)