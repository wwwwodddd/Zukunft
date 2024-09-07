for t in range(int(input())):
	k = int(input()) + 1
	while k * k * k % 1000 != 888:
		k += 1
	print(k)