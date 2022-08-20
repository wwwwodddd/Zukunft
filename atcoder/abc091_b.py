c = {}
n = int(input())
for i in range(n):
	s = input()
	c[s] = c.get(s, 0) + 1
n = int(input())
for i in range(n):
	s = input()
	c[s] = c.get(s, 0) - 1
z = 0
for i in c:
	z = max(z, c[i])
print(z)