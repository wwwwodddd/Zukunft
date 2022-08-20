a, b, c, d, e = sorted(map(int, input().split()))
if a == b == c and d == e or a == b and c == d == e:
	print('Yes')
else:
	print('No')