
a = []
for i in open('p107_network.txt').readlines():
	a.append(map(int, i.replace('-', '99999999').split(',')))

n = len(a)
d = [99999999 for i in range(40)]
v = [0 for i in range(40)]
d[0] = 0;
ans = 0
s = 0
for i in range(40):
	for j in range(i):
		if a[i][j] != 99999999:
			s += a[i][j]
for i in range(40):
	mind = 99999999
	minp = -1
	for j in range(40):
		if v[j] == 0 and mind > d[j]:
			mind = d[j]
			minp = j
	ans += mind
	v[minp] = 1
	for j in range(40):
		d[j] = min(d[j], a[minp][j])

print s - ans
