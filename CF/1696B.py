for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	i = 0
	while i < n and a[i] == 0:
		i += 1
	a = a[i:]
	while a and a[-1] == 0:
		a.pop()
	if sum(a) == 0:
		print(0)
	elif a.count(0):
		print(2)
	else:
		print(1)