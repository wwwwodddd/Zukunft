LIMIT = 190
v = [True for i in range(LIMIT)]
v[0] = v[1] = False
p = []
s = 1
for i in range(LIMIT):
	if v[i]:
		s *= i
		p.append(i)
		for j in range(i + i, LIMIT, i):
			v[j] = False
		
n = len(p) / 2
def gen(a, n):
	L = [1 for i in range(2 ** n)]
	for i in range(n):
		L[1 << i] = a[i]
	for i in range(2 ** n):
		L[i] = L[i - (i & -i)] * L[i & -i]
	return L

L = gen(p[:n], n)
R = gen(p[n:], n)

L.sort()
R.sort()
ans = 1
j = 2 ** n - 1
print len(L), len(R)
for i in range(2 ** n):
	while L[i] * L[i] * R[j] * R[j] > s:
		j -= 1
	ans = max(ans, L[i] * R[j])
print ans, s
