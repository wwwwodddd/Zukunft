h,w,x,y=map(int,input().split())
a=[input()for i in range(h)]
z=-3
for p,q in(0,1),(0,-1),(1,0),(-1,0):
	s,t=x-1,y-1
	while 0<=s<h and 0<=t<w and a[s][t]=='.':
		z+=1
		s+=p
		t+=q
print(z)