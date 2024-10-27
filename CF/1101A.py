for t in range(int(input())):
	l, r, d = map(int, input().split())
	if d < l:
		print(d)
	else:
		print(r // d * d + d)
