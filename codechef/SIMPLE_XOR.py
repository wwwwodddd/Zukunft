for t in range(int(input())):
	l, r = map(int, input().split())
	if l & 1:
		l += 1
	if l + 3 <= r:
		print(l, l + 1, l + 2, l + 3)
	else:
		print(-1)