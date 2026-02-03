for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = sorted(a)
	p = n - 1
	while a[p] == b[p] and p >= 0:
		p -= 1
	if p == -1:
		print(0)
	else:
		print(a[p])