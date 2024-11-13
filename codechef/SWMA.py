for t in range(int(input())):
	a, b = input().split()
	if sorted(a, reverse=True) > sorted(b):
		print('Yes')
	else:
		print('No')