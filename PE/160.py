def F(x,y):
	if x==0:
		return 0
	return x/y+F(x/y,y)
f5=[0]*3300
f5[0]=1
for i in range(1, 3125):
	if i % 5 == 0:
		f5[i] = f5[i - 1]
	else:
		f5[i] = f5[i - 1] * i % 3125
def G5(x):
	if x == 0:
		return 1
	return pow(f5[3124], x / 3125, 3125) * G5(x / 5) * f5[x % 3125] % 3125
f2=[0]*100
f2[0]=1
for i in range(1,32):
	if i % 2 == 0:
		f2[i] = f2[i - 1]
	else:
		f2[i] = f2[i - 1] * i % 32
def G2(x):
	if x==0:
		return 1
	return pow(f2[31], x / 32, 32) * G2(x / 2) * f2[x % 32] % 32
n=input()
c2=F(n,2)
c5=F(n,5)
print F(n,2),F(n,5)

z2=G2(n)*pow(2,c2-c5,32)*pow(13,c5,32)%32
z5=G5(n)*pow(1563,c5,3125)%3125
print z2,z5
for i in range(100000):
	if i%32==z2 and i%3125==z5:
		print i
