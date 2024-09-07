import sys
t = int(input())
for tt in range(t):
	n = int(input())
	a = [0] + list(map(int, input().split()))
	z = 0
	for i in range(20):
		s = 0
		b = []
		for j in range(1, n + 1):
			if j >> i & 1:
				s += a[j]
				b.append(j)
		if len(b) == 0:
			break
		print('?', len(b), *b)
		sys.stdout.flush()
		t = int(input())
		if s < t:
			z |= 1 << i
	print('!', z)