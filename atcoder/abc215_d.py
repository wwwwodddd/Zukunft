n, m = map(int, input().split())
v = [0 for i in range(100001)]
for i in map(int, input().split()):
	v[i] = 1
v[1] = 0
for i in range(2, 100001):
	for j in range(2 * i, 100001, i):
		v[i] |= v[j]
for i in range(2, 100001):
	for j in range(2 * i, 100001, i):
		v[j] |= v[i]
z = [i for i in range(1, m + 1) if not v[i]]
print(len(z))
for i in z:
	print(i)