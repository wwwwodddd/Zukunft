for t in range(int(input())):
	n = int(input())
	a = [list(map(int, input().split())) for i in range(n)]
	z = 0
	for i in range(n):
		for j in range(i):
			z = max(z, a[i][0] * a[j][1] + a[i][1] * a[j][0])
	print(z)