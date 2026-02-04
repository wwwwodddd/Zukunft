for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	if 1 in a or sum(a) % 2:
		print('CHEF')
	else:
		print('CHEFINA')