n = int(input())
a = list(map(int, input().split()))
s = 0
for i in range(n):
	if i + 1 == a[i]:
		s += a[i]
print(s - 99)