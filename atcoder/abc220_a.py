a,b,c=map(int,input().split())
if b//c*c<a:
	print(-1)
else:
	print(b//c*c)