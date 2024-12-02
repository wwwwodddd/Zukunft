n, m = map(int, input().split())
l = 0
for s in input().split():
	if l + len(s) > m:
		print()
		l = 0
	if l > 0:
		print(' ', end='')
	print(s, end='')
	l += len(s)
print()