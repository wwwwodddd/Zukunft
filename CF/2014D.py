for t in range(int(input())):
	n, d, k = map(int, input().split())
	s = [0 for i in range(n + 1)]
	for i in range(k):
		l, r = map(int, input().split())
		s[max(l - d, 0)] += 1
		s[r] -= 1
	for i in range(n):
		s[i + 1] += s[i]
	print(s.index(max(s[:-d])) + 1, s.index(min(s[:-d])) + 1)
