import collections
for t in range(int(input())):
	s = collections.Counter(map(int, input()))
	z = ''
	for i in range(65, 91):
		s[i % 10] -= 1
		s[i // 10] -= 1
		if s[i % 10] >= 0 and s[i // 10] >= 0:
			z += chr(i)
		s[i // 10] += 1
		s[i % 10] += 1
	print(z)
