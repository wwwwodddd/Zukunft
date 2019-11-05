import itertools


def Prime(x):
	if x < 2:
		return False
	i = 2
	while i * i <= x:
		if x % i == 0:
			return False
		i += 1
	return True

def N(n, d, m):
	re = []
	for b in itertools.combinations(range(n), m):
		f = [0]
		for i in range(n):
			g = []
			if i in b:
				for j in f:
					for k in range(10):
						g.append(j * 10 + k)
			else:
				for j in f:
					g.append(j * 10 + d)
			f = g
		re += filter(Prime, f)
	return filter(lambda x: x >= 10 ** (n - 1), re)

def M(n, d):
	for c in range(1, n):
		t = N(n, d, c)
		if len(t) > 0:
			return (len(t), sum(t))
	assert False

s = 0
for d in range(10):
	t = M(10, d)
	s += t[1]
	print d, t
print s
