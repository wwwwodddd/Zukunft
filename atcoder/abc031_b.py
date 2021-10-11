l,h=map(int,input().split())
n=int(input())
for i in range(n):
	a=int(input())
	print([max(l-a,0),-1][a>h])