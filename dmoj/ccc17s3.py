n = int(input())
a = list(map(int, input().split()))
c = [0 for i in range(4001)]
z = [0 for i in range(4001)]
for i in a:
	c[i] += 1
for i in range(2001):
	for j in range(i):
		z[i + j] += min(c[i], c[j])
	z[i * 2] += c[i] // 2
print(max(z), z.count(max(z)))