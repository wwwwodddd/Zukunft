from collections import Counter
c = [Counter(), Counter()]
n = input()
a = map(int, raw_input().split())
for i in range(n):
	c[i & 1][a[i]] += 1
p = [(0, 0)]
q = [(0, 0)]
for i in c[0]:
	p.append((c[0][i], i))
for i in c[1]:
	q.append((c[1][i], i))
p.sort()
q.sort()
if p[-1][1] == q[-1][1]:
	print n - max(p[-1][0] + q[-2][0], p[-2][0] + q[-1][0])
else:
	print n - p[-1][0] - q[-1][0]
