for t in range(int(input())):
	n = int(input())
	a = [1000] * 5 + list(map(int, input().split()))
	z = 0
	for i in range(5, n + 5):
		if a[i] < min(a[i - 5 : i]):
			z += 1
	print(z)