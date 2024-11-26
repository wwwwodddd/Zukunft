for t in range(int(input())):
	n, k = map(int, input().split())
	s = sum(map(int, input().split()))
	if s % 2 == 0 and k == 1:
		print('odd')
	else:
		print('even')
