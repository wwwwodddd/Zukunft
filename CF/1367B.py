for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	s = sum(i % 2 for i in a)
	if s == n // 2:
		print(sum(i % 2 for i in a[::2]))
	else:
		print(-1)