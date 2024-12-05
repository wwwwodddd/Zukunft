from collections import Counter
n = int(input())
c = Counter(map(int, input().split()))
z = 0
for i in c:
	if i > 0:
		z += c[i] * c[-i]
z += c[0] * (c[0] - 1) // 2
print(z)
