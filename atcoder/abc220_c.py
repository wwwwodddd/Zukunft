n=int(input())
a=list(map(int,input().split()))
x=int(input())
s=sum(a)
z=x//s*n
x%=s
for i in a:
	x-=i
	z+=1
	if x<0:
		break
print(z)