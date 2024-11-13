for t in range(int(input())):
	n = int(input())
	s = input()
	z = ''
	for i in range(0, n, 2):
		z += 'ATCG'[int(s[i : i + 2], 2)]
	print(z)
