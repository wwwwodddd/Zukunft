a,b,c,d=map(int,input().split())
if b*c<d*a:
	print('AOKI')
elif b*c>d*a:
	print('TAKAHASHI')
else:
	print('DRAW')