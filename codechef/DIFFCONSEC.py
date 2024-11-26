for t in range(int(input())):
	n = int(input())
	s = input()
	z = 0
	for i in range(1, n):
		z += (s[i - 1] == s[i])
	print(z)