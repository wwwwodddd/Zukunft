for t in range(int(input())):
	n = int(input())
	print(bin(n % 2048).count('1') + n // 2048)
