n=int(input())
if n<100:
	n=0
elif n<=5000:
	n//=100
elif n<=30000:
	n=n//1000+50
elif n<=70000:
	n=(n//1000-30)//5+80
else:
	n=89
print('%02d'%n)