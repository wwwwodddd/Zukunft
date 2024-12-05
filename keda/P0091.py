input()
a = list(map(int, input().split()))
for i in range(1, len(a)):
	a[i] += a[i - 1]
print(*a)