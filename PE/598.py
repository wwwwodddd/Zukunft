import fractions
n = 100
p = []
v = [0 for i in range(n)]
for i in range(2, n):
	if v[i] > 0:
		continue
	p.append(i)
	for j in range(i, n, i):
		v[j] = i

print len(p)
c = [0 for i in range(len(p))]
for i in range(len(p)):
	t = n
	while t > 0:
		t /= p[i]
		c[i] += t

print c

b = 0

first = c[:3]
second = c[3:]

f = {fractions.Fraction(1): 1}
for i in first:
	g = {}
	for j in f:
		for k in range(i + 1):
			u = j * (k + 1) / (i - k + 1)
			if u not in g:
				g[u] = 0
			g[u] += f[j]
	f = g
	b += 1
	print len(f), i

firstresult = f

f = {fractions.Fraction(1): 1}
for i in second:
	g = {}
	for j in f:
		for k in range(i + 1):
			u = j * (k + 1) / (i - k + 1)
			if u not in g:
				g[u] = 0
			g[u] += f[j]
	f = g
	b += 1
	print len(f), i

secondresult = f

ans = 0
for i in firstresult:
	if i in secondresult:
		ans += firstresult[i] * secondresult[i]
print ans / 2
