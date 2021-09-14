input()
a=list(map(int,input().split()))
s=1000
for x,y in zip(a,a[1:]):
	s=max(s,s//x*y+s%x)
print(s)