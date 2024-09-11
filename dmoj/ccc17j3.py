a, b = map(int, input().split())
c, d = map(int, input().split())
e = int(input()) - abs(a - c) - abs(b - d)
if e >= 0 and e % 2 == 0:
	print('Y')
else:
	print('N')