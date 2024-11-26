import math
for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	g = math.gcd(*a)
	print(sum(g != i for i in a))