for t in range(int(input())):
	n, m = map(int, input().split())
	a = [n]
	for i in range(60):
		if ~n >> i & 1 and (n + (1 << i)) <= m:
			a.append(n + (1 << i))
	if len(a) > 1:
		print(len(a))
		print(*a)
	else:
		print(-1)