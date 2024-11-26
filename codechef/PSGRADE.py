for t in range(int(input())):
	am, bm, cm, t, a, b, c = map(int, input().split())
	if a >= am and b >= bm and c >= cm and a + b + c >= t:
		print('YES')
	else:
		print('NO')