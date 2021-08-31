n = int(input())
def F(n):
	if n == 0:
		return ''
	if n % 2:
		return F(n - 1) + 'A'
	else:
		return F(n // 2) + 'B'
print(F(n))