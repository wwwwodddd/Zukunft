for t in range(int(input())):
	n = int(input())
	b = list(map(int, input().split()))
	a = [b[0]]
	for i in range(1, n - 1):
		a.append(b[i - 1] | b[i])
	a.append(b[-1])
	for i in range(n - 1):
		if (a[i] & a[i + 1]) != b[i]:
			print(-1)
			break
	else:
		print(*a)