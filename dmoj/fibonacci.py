p = 1000000007
def F(n): # return fib(n), fib(n+1)
	if n == 0:
		return 0, 1
	if n & 1:
		x, y = F(n - 1)
		return (y, (x + y) % p)
	else:
		x, y = F(n >> 1)
		return (2 * y - x) * x % p, (x * x + y * y) % p
print(F(int(input()))[0])