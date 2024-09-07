m,a,c,x0,n,g=map(int,input().split())
def S(r,n):
	if n==0:
		return 0
	elif n&1:
		return (S(r,n-1)*r+1)%m
	else:
		return S(r*r%m,n//2)*(r+1)%m
print((x0*pow(a,n,m)+S(a,n)*c)%m%g)