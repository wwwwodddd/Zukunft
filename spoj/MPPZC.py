t = int(input())
for tt in range(t):
	s = input()
	n = int(s)
	if n == 0:
		print(0)
	else:
		l = 0
		x = 10 ** (len(s) // 2)
		for i in range(30):
			x = (x + n // x) // 2
		x += 2
		while x * x > n:
			x -= 1
		print(x)