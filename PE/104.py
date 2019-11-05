p=10**9
xf=1
xb=1
yf=1
yb=1
c=2
while True:
	c+=1
	xf,yf=xf+yf,xf
	if xf>10**15:
		xf/=10
		yf/=10
	xb,yb=(xb+yb)%p,xb
	if len(set(str(xf)[:9])-set(["0"]))==9 and len(set(str(xb))-set(["0"]))==9:
		print c
		print xb
		break
