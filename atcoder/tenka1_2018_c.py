n=int(input())
a=sorted(int(input())for i in range(n))
m=n//2
if n%2:
	print(sum(a[m+2:])*2-sum(a[:m-1])*2+a[m+1]-a[m-1]+max(a[m+1]-a[m],a[m]-a[m-1]))
else:
	print(sum(a[m+1:])*2-sum(a[:m-1])*2+a[m]-a[m-1])