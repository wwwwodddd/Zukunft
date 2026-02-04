def F(a):
	z = s = 0
	for i in a:
		s += i
		z = max(z, s)
	return z
for t in range(int(input())):
	n = int(input())
	a = F(map(int, input().split()))
	m = int(input())
	b = F(map(int, input().split()))
	print(a + b)