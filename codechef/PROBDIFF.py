for t in range(int(input())):
	a = sorted(map(int, input().split()))
	if a[0] == a[3]:
		print(0)
	elif a[0] == a[2] or a[1] == a[3]:
		print(1)
	else:
		print(2)
