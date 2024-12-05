import functools
@functools.cache
def F(n):
	if n == 0:
		return 1
	return F(n // 2) + F(n // 3)
print(F(int(input())))