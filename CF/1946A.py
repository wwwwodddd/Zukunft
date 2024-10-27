for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	p = (n - 1) // 2
	while p + 1 < n and a[p] == a[p + 1]:
		p += 1
	print(p - (n - 1) // 2 + 1)