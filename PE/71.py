n=input()
zx,zy=0,1
for i in range(1,n+1):
	y=i
	x=3*i/7
	if 3*i==7*x:
		x-=1
	if x*zy>y*zx:
		zx,zy=x,y
print zx,zy
