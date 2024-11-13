import math
for t in range(int(input())):
	n = int(input())
	print(math.gcd(*map(int, input().split())) * n)
