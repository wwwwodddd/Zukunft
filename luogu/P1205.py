n = int(input())
a = [input().strip() for i in range(n)]
b = [input().strip() for i in range(n)]
def rot(a):
	c = []
	for i in range(n):
		c.append(''.join(a[n - j - 1][i] for j in range(n)))
	return c
def flip(a):
	c = []
	for i in range(n):
		c.append(a[i][::-1])
	return c
if rot(a) == b:
	print(1)
elif rot(rot(a)) == b:
	print(2)
elif rot(rot(rot(a))) == b:
	print(3)
elif flip(a) == b:
	print(4)
elif flip(rot(a)) == b or flip(rot(rot(a))) == b or flip(rot(rot(rot(a)))) == b:
	print(5)
elif a == b:
	print(6)
else:
	print(7)