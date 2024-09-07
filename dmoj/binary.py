for t in range(int(input())):
	n = int(input())
	a = []
	if n == 0:
		a.append('0000')
	while n > 0:
		b = n % 16
		n //= 16
		a.append(bin(b + 16)[3:])
	print(*a[::-1])