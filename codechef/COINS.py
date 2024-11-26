from functools import cache
@cache
def F(n):
	if n < 12:
		return n
	return F(n // 2) + F(n // 3) + F(n // 4)
while True:
	try:
		print(F(int(input())))
	except:
		break