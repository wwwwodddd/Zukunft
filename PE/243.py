p,q=15499,94744
n=d=1
def P(x):
	for i in range(2,int(x**0.5)+1):
		if x%i==0:
			return 0
	return 1
a=[2,3,5,7,11,13,17,19,23,29]
ans=1115464350
def G(x,y,i):
	print x,y,i
	global ans
	if y*q<(x-1)*p:
		ans=x
	if x>=ans:
		return
	x*=a[i]
	y*=a[i]-1
	if x>=ans:
		return
	for j in range(30):
		G(x,y,i+1)
		if x>=ans:
			return
		x*=a[i]
		y*=a[i]
		if x>=ans:
			return
G(1,1,0)
print ans
'''
for i in a:
	n*=i-1
	d*=i
	if n*q<p*(d-1):
		print d,i
	for j in a:
		if j*n*q<p*(j*d-1):
			print j*d,i
'''
