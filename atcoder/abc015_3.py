n,k=map(int,input().split())
s=set([0])
for i in range(n):
	t=set()
	for j in map(int,input().split()):
		for k in s:
			t.add(j^k)
	s=t
print(['Nothing','Found'][0 in s])