from fractions import gcd
def F(a, b, c, d):
	if a < b or d < b:
		return False
	a -= c
	a %= gcd(b, d)
	if a == 0:
		a = gcd(b, d)
	return a - b >= -c
for t in range(input()):
	a, b, c, d = map(int, raw_input().split())
	print ['No', 'Yes'][F(a, b, c, d)]
