a, b, c, d = map(int, input().split())
if c * 60 + d < a * 60 + b:
	print('Aoki')
else:
	print('Takahashi')
