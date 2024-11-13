for t in range(int(input())):
	n = int(input())
	z = 0
	for i in range(n):
		z ^= int(input())
	print(z)