import math
for t in range(int(input())):
	n, m = map(int, input().split())
	print(math.comb(n - 1, m - 1))
