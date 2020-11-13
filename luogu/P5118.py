a = map(int, raw_input().split())
b = map(int, raw_input().split())
s = set([])
s.add(0)
for i in range(10):
	for j in range(10):
		s.add(a[i] - b[j])
for i in range(10):
	for j in range(10):
		for k in range(i):
			for l in range(j):
				s.add(a[i] + a[k] - b[j] - b[l])
print len(s)