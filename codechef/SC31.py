for t in range(int(input())):
	n = int(input())
	z = [0 for i in range(10)]
	for i in range(n):
		s = input()
		for j in range(10):
			if s[j] == '1':
				z[j] ^= 1
	print(sum(z))