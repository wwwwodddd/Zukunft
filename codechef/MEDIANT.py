for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	mx = max(a)
	mn = min(a)
	for i in range(n):
		if a[i] == mn:
			mni = i
		if a[i] == mx:
			mxi = i
	if mxi < mni:
		print(-1)
	else:
		print(n - 2)
		for i in range(n - 2):
			print(1, 3)