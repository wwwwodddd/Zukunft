for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	if a == b or a == b[::-1]:
		print('Bob')
	else:
		print('Alice')