for t in range(int(input())):
	c, d, l = map(int, input().split())
	if l % 4 == 0 and 4 * max(d, c - d) <= l <= 4 * (c + d):
		print('yes')
	else:
		print('no')
