a = [[]for i in range(200)]
def sq(x):
	return int(x ** 0.5) ** 2 == x
for i in range(1, 200):
	j = 0
	while True:
		if len(a[j]) == 0 or sq(a[j][-1] + i):
			a[j].append(i)
			break
		j += 1

for i in range(10):
	print i + 1, a[i], a[i][2] - a[i][0]


def P(f, r):
	if f == 1:
		return r * (r + 1) / 2
	if f % 2 == 0:
		u = f * f / 2
		v = (f + 1) * (f + 1) - f * f / 2
		if r % 2 == 0:
			n = (r - 2) / 2
			s = f * 2 + 5
			return v + n * (n - 1) / 2 * 4 + n * s

		if r % 2 == 1:
			n = (r - 1) / 2
			s = f * 2 + 3
			return u + n * (n - 1) / 2 * 4 + n * s

	if f % 2 == 1:
		u = (f * f - 1) / 2
		v = f * f - (f * f - 1) / 2

		if r % 2 == 0:
			n = (r - 2) / 2
			s = f * 2 + 3
			return v + n * (n - 1) / 2 * 4 + n * s

		if r % 2 == 1:
			n = (r - 1) / 2
			s = f * 2 + 1
			return u + n * (n - 1) / 2 * 4 + n * s

for i in range(10):
	print P(4, i + 1)

ans = 0
for i in range(28):
	for j in range(13):
		f = 2 ** i * 3 ** j
		ans += P(f, 71328803586048 / f)

print ans % (10 ** 8)
#print P(3, 1)