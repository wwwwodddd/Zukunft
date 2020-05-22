k, a, b = map(int, raw_input().split())
if a >= k:
	print 1
elif a <= b:
	print -1
else:
	print 1 + (k - b - 1) / (a - b) * 2