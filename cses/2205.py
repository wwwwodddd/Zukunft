n = int(input())
for i in range(2 ** n):
	print(bin(2 ** n + i ^ (i >> 1))[3:])