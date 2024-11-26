for t in range(int(input())):
	n = int(input())
	z = 0
	for i in range(n):
		x, y = map(int, input().split())
		z += (y - x > 5)
	print(z)