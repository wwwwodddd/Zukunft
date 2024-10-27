for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	s = 0
	for i in range(n):
		if i & 1:
			s -= a[i]
		else:
			s += a[i]
	print(s)