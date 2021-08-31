a,b,k=map(int,input().split())
for i in range(k):
	if i%2:
		b//=2
		a+=b
	else:
		a//=2
		b+=a
print(a,b)