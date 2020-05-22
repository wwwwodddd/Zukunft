n = input()
x = []
y = []
for i in range(n):
	a, b = map(int, raw_input().split())
	x.append(a)
	y.append(b)
for i in range(n):
	if (x[0] + y[0]) % 2 != (x[i] + y[i]) % 2:
		print -1
		exit()
d = [1 << i for i in range(32)][::-1]
if (x[0] + y[0]) % 2 == 0:
	d.append(1)

print len(d)
for i in d:
	print i,
print
for i in range(n):
	s = ''
	for j in d:
		if abs(x[i]) > abs(y[i]):
			if x[i] > 0:
				x[i] -= j
				s += 'R'
			else:
				x[i] += j
				s += 'L'
		else:
			if y[i] > 0:
				y[i] -= j
				s += 'U'
			else:
				y[i] += j
				s += 'D'
	print s
