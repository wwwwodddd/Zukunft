for t in range(int(input())):
	input()
	a = list(map(int, input().split()))
	for i in range(len(a)):
		if a[i] >= a[-1]:
			print(len(a) - i - 1)
			break
