import math
for t in range(int(input())):
	n = int(input())
	c = min(map(int, input().split()))
	print((n + c - 1) // c)