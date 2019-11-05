import itertools
a = [i * (i + 1) / 2 for i in range(200)]
b = [i * i for i in range(200)]
c = [i * (3 * i - 1) / 2 for i in range(200)]
d = [i * (2 * i - 1) for i in range(200)]
e = [i * (5 * i - 3) / 2 for i in range(200)]
f = [i * (3 * i - 2) for i in range(200)]


def wocao(a, b, c, d, e, f):

	A = []
	for i in a:
		if len(str(i)) == 4:
			A.append(i)

	B = []
	for i in A:
		for j in b:
			if len(str(j)) == 4:
				if i % 100 == j / 100:
					B.append([i, j])

	C = []
	for i in B:
		for j in c:
			if len(str(j)) == 4:
				if i[-1] % 100 == j / 100:
					C.append(i + [j])

	D = []
	for i in C:
		for j in d:
			if len(str(j)) == 4:
				if i[-1] % 100 == j / 100:
					D.append(i + [j])

	E = []
	for i in D:
		for j in e:
			if len(str(j)) == 4:
				if i[-1] % 100 == j / 100:
					E.append(i + [j])

	F = []
	for i in E:
		for j in f:
			if len(str(j)) == 4:
				if i[-1] % 100 == j / 100:
					F.append(i + [j])

	for i in F:
		if i[-1] % 100 == i[0] / 100:
			print i
			print sum(i)
for i in itertools.permutations([a, b, c, d, e, f], 6):
	wocao(i[0], i[1], i[2], i[3], i[4], i[5])

