n=int(input())
a=[int(input())for i in range(n)]
if n&1:
	a.append(0)
a.sort()
print(sum(a[i+1]**2-a[i]**2 for i in range(0,n,2))*3.1415926)