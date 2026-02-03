for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	c1 = a.count(1)
	c2 = a.count(2)
	c3 = a.count(3)
	print(c1 * (c1 - 1) // 2 + c2 * (c1 + c3))
