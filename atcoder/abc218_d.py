n=int(input())
a=set()
z=0
for i in range(n):
	a.add(tuple(map(int,input().split())))
for x1,y1 in a:
	for x2,y2 in a:
		if x1<x2 and y1<y2 and (x1,y2) in a and (x2,y1) in a:
			z+=1
print(z)