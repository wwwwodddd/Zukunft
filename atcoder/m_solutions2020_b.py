a,b,c=map(int,input().split())
k=int(input())
while a>=b:
	b*=2
	k-=1
while b>=c:
	c*=2
	k-=1
print('YNeos'[k<0::2])