for t in range(int(input())):
	a, b, c = map(int, input().split())
	i = 1
	while a % i == 0 or b % i == 0 or c % i == 0:
		i += 1
	print(i)