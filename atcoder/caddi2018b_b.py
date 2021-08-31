n,h,w=map(int,input().split())
z=0
for i in range(n):
	a,b=map(int,input().split())
	if a>=h and b>=w:
		z+=1
print(z)