import itertools
q = int(input())
a = [input(), input(), input(), input()]
for i in range(q):
	s = input()
	for p in itertools.permutations(a, len(s)):
		f = True
		for i in range(len(s)):
			if s[i] not in p[i]:
				f = False
				break
		if f:
			print('YES')
			break
	else:
		print('NO')
