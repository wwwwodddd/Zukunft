for t in range(int(input())):
	a,s=map(int,input().split())
	if s<2*a or (s-2*a&a)>0:
		print('No')
	else:
		print('Yes')