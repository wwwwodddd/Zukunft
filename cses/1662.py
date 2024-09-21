from collections import Counter
n = int(input())
z = s = 0
c = [0 for i in range(n)]
c[s] += 1
for i in map(int, input().split()):
	s = (s + i) % n
	z += c[s]
	c[s] += 1
print(z)