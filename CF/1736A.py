for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	z = 0
	for i in range(n):
		z += (a[i] != b[i])
	z = min(z, abs(sum(a) - sum(b)) + 1)
	print(z)