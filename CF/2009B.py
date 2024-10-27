import math
for t in range(int(input())):
	n = int(input())
	a = [input().index('#') + 1 for i in range(n)]
	print(*a[::-1])
