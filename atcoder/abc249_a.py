a, b, c, d, e, f, x = map(int, input().split())
u = (x // (a + c) * a + min(a, x % (a + c))) * b;
v = (x // (d + f) * d + min(d, x % (d + f))) * e;
if u > v:
	print('Takahashi')
elif u < v:
	print('Aoki')
else:
	print('Draw')
