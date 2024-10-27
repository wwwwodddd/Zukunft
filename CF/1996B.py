for t in range(int(input())):
	n, m = map(int, input().split())
	for i in range(n):
		s = input()
		if i % m == 0:
			print(s[::m])
