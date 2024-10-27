for t in range(int(input())):
	n = int(input())
	i = 1
	while n % i == 0:
		i += 1
	print(i - 1)