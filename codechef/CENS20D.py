for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = 0
	for i in range(n):
		for j in range(i + 1, n):
			if (a[i] & a[j]) == a[i]:
				z += 1
	print(z)