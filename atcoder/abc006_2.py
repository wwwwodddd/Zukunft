x,y,z=1,0,0
for i in range(int(input())):
	x,y,z=y,z,(x+y+z)%10007
print(x)