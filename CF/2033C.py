for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = 0
	for i in range(1, (n + 1) // 2):
		z += min((a[i - 1] == a[i]) + (a[n - i] == a[n - i - 1]), (a[i - 1] == a[n - i - 1]) + (a[n - i] == a[i]))
	if n % 2 == 0:
		if a[n // 2] == a[n // 2 - 1]:
			z += 1
	print(z)