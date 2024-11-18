for t in range(int(input())):
	n = int(input())
	s = [0 for i in range(2 * n + 5)]
	for i, x in enumerate(map(int, input().split())):
		s[i + 1] += n // 2 * x
		s[i + 2] += x
		s[i + 3] += -n // 2 * x
		s[i + n + 1] += -n // 2 * x
		s[i + n + 2] += x
		s[i + n + 3] += n // 2 * x
	for i in range(2, 2 * n):
		s[i] = 2 * s[i - 2] - s[i - 4] + s[i]
	for i in range(n, 2 * n):
		s[i - n] += s[i]
	print(*s[:n])
