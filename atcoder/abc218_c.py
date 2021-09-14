n=int(input())
a=[]
for i in range(n):
	s=input()
	for j in range(n):
		if s[j]=='#':
			a.append((i,j))
b=[]
for i in range(n):
	s=input()
	for j in range(n):
		if s[j]=='#':
			b.append((i,j))
def rot(a):
	b=[]
	for x,y in a:
		b.append((-y,x))
	return b
def nom(a):
	minx = min(x for x,y in a)
	miny = min(y for x,y in a)
	b=[]
	for x,y in a:
		b.append((x-minx,y-miny))
	return sorted(b)
for i in range(4):
	a=nom(a)
	b=nom(b)
	if a==b:
		print('Yes')
		break
	a=rot(a)
else:
	print('No')