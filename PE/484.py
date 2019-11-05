a = [2, 3, 5, 7, 11, 13]
b = [0 for i in range(2 ** 6)]
z = 0
def cal(n, a):
	z = 0
	for i in range(2 ** len(a)):
		c = 1
		t = 1
		for j in range(len(a)):
			if i >> j & 1:
				c = -c;
				t *= a[j]
		z += n / t * c
	return z

for i in range(2 ** 6):
	t = 1
	for j in range(6):
		if i >> j & 1:
			t *= a[j] ** a[j]
	b[i] += t
	for j in range(2 ** 6):
		if i != j and (i & j) == i:
			b[j] -= b[i]; 

for i in range(100):
	if 10 ** 15 / (2 ** 2) ** i == 0:
		break
	for j in range(100):
		if 10 ** 15 / (3 ** 3) ** j == 0:
			break
		for k in range(100):
			if 10 ** 15 / (5 ** 5) ** k == 0:
				break
			for l in range(100):
				if 10 ** 15 / (7 ** 7) ** l == 0:
					break
				for p in range(100):
					if 10 ** 15 / (11 ** 11) ** p == 0:
						break
					for q in range(100):
						if 10 ** 15 / (13 ** 13) ** q == 0:
							break
						w = []
						c = 0
						if i:
							w.append(2)
							c += 1
						if j:
							w.append(3)
							c += 2
						if k:
							w.append(2)
							c += 4
						if l:
							w.append(7)
							c += 8
						if p:
							w.append(11)
							c += 16
						if q:
							w.append(13)
							c += 32
						z += b[c] * cal(16 / (2 ** 2) ** i / (3 ** 3) ** j / (5 ** 5) ** k / (7 ** 7) ** l / (11 ** 11) ** p / (13 ** 13) ** q, w)
print z