for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	if len(set(a)) == 1:
		print(-1)
	else:
		mx = max(a)
		b = [i for i in a if i != mx]
		c = [i for i in a if i == mx]
		print(len(b), len(c))
		print(*b)
		print(*c)
