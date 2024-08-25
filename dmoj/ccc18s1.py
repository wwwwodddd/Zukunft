n = int(input())
a = []
for i in range(n):
	a.append(int(input()))
a.sort()
print(min(a[i] - a[i - 2] for i in range(2, len(a))) / 2)