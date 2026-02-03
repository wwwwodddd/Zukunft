import collections
for t in range(int(input())):
	n, c = map(int, input().split())
	s = input()
	a = sorted(collections.Counter(s).values())
	z = s = len(a) * c
	t = 0
	for i in a:
		s -= c
		s += (t + 1 + t + i) * i // 2
		z = min(z, s)
		t += i
	print(z)
