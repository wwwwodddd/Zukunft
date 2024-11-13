for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	z = 0
	for i in range(n):
		z += max(a[i] - b[i], 0)
	if sum(a) != sum(b):
		z = -1
	print(z)