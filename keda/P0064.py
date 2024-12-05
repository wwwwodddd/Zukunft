def F(n): # return fib(n), fib(n+1)
	if n == 0:
		return 0, 1
	if n & 1:
		x, y = F(n - 1)
		return (y, (x + y))
	else:
		x, y = F(n >> 1)
		return (2 * y - x) * x, (x * x + y * y)
print(F(int(input()))[0])