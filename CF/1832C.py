for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = [a[0]]
	for i in range(1, n - 1):
		if b[-1] <= a[i] <= a[i + 1]:
			pass
		elif b[-1] >= a[i] >= a[i + 1]:
			pass
		else:
			b.append(a[i])
	if b[-1] != a[-1]:
		b.append(a[-1])
	print(len(b))