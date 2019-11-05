from fractions import *
ans=0
a=map(int,"2 3 4 5 6 7 8 9 10 12 12 14 15 18 20 21 24 28 30 35 36 40 42 45 56 60 63 70 72".split())
s=[]
def F(x,i):
	global ans
	if x==0:
		ans+=1
		print "FIND",s
		return
	if x<0:
		return
	if i==len(a):
		return
	w=0.0
	for j in range(i,len(a)):
		w+=1./a[j]/a[j]
	if not float(x)>w and x>w:
	 	print x,Fraction(w),float(x),w
		raw_input()
	if x>w:
		return
	for j in range(i,len(a)):
		s.append(a[j])
		F(x-Fraction(1,a[j]*a[j]),j+1)
		s.pop()
F(Fraction(1,2),0)
print ans

