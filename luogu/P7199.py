t = int(input())
def F(x):
	return x // 9 * 45 + x % 9 * (x % 9 + 1) // 2
for tt in range(t):
	l, r = map(int, input().split())
	print(F(r) - F(l - 1))