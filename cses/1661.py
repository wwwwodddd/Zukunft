from collections import Counter
n, x = map(int, input().split())
z = s = 0
c = Counter()
c[s] += 1
for i in map(int, input().split()):
	s += i
	z += c[s - x]
	c[s] += 1
print(z)