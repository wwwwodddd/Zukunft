for t in range(int(input())):
	n, m = map(int, input().split())
	a = sorted(map(int, input().split()), reverse=True)
	b = sorted(map(int, input().split()), reverse=True)
	if n >= 4 and m >= 4 and n + m >= 11:
		print(sum(a[:4]) + sum(b[:4]) + sum(sorted(a[4:] + b[4:])[-3:]))
	else:
		print(-1)