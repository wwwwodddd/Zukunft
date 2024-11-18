for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	z = 0
	for i in range(len(a) // 2):
		z += a[-i - 1] - a[i]
	print(z)