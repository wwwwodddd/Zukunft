t = eval(input().replace(' ', '*'))
s = sum(map(float, input().split()))
if s >= t:
	print('YES')
else:
	print('NO')