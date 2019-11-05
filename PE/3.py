n=input()
for i in range(2,int(n**0.5)+1):
	while n%i==0 and n>i:
		n/=i
print n
