n = int(input())
a = sorted(x - y for x, y in zip(map(int, input().split()), map(int, input().split())))
j = n
z = 0
for i in range(n):
	while j > i and a[j - 1] + a[i] > 0:
		j -= 1
	z += n - max(j, i + 1)
print(z)