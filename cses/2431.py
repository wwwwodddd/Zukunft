for t in range(int(input())):
	k = int(input()) - 1
	d = 1
	while k >= 9 * 10 ** (d - 1) * d:
		k -= 9 * 10 ** (d - 1) * d
		d += 1
	print(str(k // d + 10 ** (d - 1))[k % d])