r1, r2 = map(int, input().split())
d1, d2 = map(int, input().split())
r1 += d1
r2 += d2
if r1 < r2:
	print('Everule')
else:
	print('Dominater')