import itertools

l = list(itertools.combinations(range(9) + [6], 6))
cnt = 0

def check(x, y):
	a = [(min(i, j), max(i, j)) for i in x for j in y]
	for i in [(0, 1), (0, 4), (0, 6), (1, 6), (2, 5), (3, 6), (4, 6), (4, 6), (1, 8)]:
		if i not in a:
			return False
	return True

for i in range(len(l)):
	for j in range(i):
		if check(l[i], l[j]):
			cnt += 1

print cnt