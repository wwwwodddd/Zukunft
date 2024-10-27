for t in range(int(input())):
	n = int(input())
	a = [0] + list(map(int, input().split()))
	for i in range(1, n + 1):
		if a[a[i]] == i:
			print(2)
			break
	else:
		print(3)