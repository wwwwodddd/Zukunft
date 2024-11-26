for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = 'yes'
	if set(a) != {1, 2, 3, 4, 5, 6, 7}:
		z = 'no'
	if a != a[::-1]:
		z = 'no'
	if sorted(a[:(n+1)//2]) != a[:(n+1)//2]:
		z = 'no'
	print(z)
