for t in range(int(input())):
	n, k, p = map(int, input().split())
	a = list(map(int, input().split()))
	z = p + sum(a) - k - max(a) * 2
	if z > 0:
		print('Varun')
	elif z < 0:
		print('Ved')
	else:
		print('Equal')