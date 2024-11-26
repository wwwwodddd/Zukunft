for t in range(int(input())):
	if sum(map(int, input().split())) == sum(map(int, input().split())):
		print('Pass')
	else:
		print('Fail')
