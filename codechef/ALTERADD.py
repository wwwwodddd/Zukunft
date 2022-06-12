for t in range(int(input())):
	x,y=map(int,input().split())
	print('YNEOS'[(y-x)%3==2::2])