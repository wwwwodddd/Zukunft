n = int(input())
a = []
for i in range(n):
	d, x, y = input().split()
	x = int(x)
	y = int(y)
	a.append([d, x, y, i])

t = set()
for i in range(n):
	for j in range(n):
		t.add(abs(a[j][1] - a[i][1]))
		t.add(abs(a[i][2] - a[j][2]))

t.remove(0)
t = sorted(list(t))

v = set()
z = [-1 for i in range(n)]
for i in range(n):
	v.add((a[i][1], a[i][2]))

lt = 0
for tt in t:
	for i in range(n):
		if a[i][0] == 'N':
			a[i][2] += tt - lt
		elif a[i][0] == 'E':
			a[i][1] += tt - lt
		if a[i][0] != 'D' and (a[i][1], a[i][2]) in v:
			z[i] = tt
			a[i][0] = 'D'
	for i in range(n):
		v.add((a[i][1], a[i][2]))
	lt = tt
for i in range(n):
	if z[i] == -1:
		print('Infinity')
	else:
		print(z[i])