for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	s = a[0]
	for i in range(1, n):
		s = (s + a[i]) // 2
	print(s)