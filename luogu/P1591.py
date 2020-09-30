t = int(input())
for tt in range(t):
	n, a = input().split()
	z = 1
	for i in range(1, int(n) + 1):
		z *= i
	print(str(z).count(a))