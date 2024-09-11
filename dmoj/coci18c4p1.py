s = input()
c = {s}
n = int(input())
for i in range(n):
	x, y = input().split()
	if s == y:
		s = x
		c.add(x)
print(s)
print(len(c))