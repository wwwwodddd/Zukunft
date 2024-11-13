for t in range(int(input())):
	a = list(map(int, input().split()))
	if sorted(a[:3], reverse=True) > sorted(a[3:], reverse=True):
		print('Alice')
	elif sorted(a[:3], reverse=True) < sorted(a[3:], reverse=True):
		print('Bob')
	else:
		print('Tie')
