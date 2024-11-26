for t in range(int(input())):
	n = int(input())
	a = sum(map(int, input().split()))
	b = sum(map(int, input().split()))
	c = sum(map(int, input().split()))
	d = sum(map(int, input().split()))
	if a > c and b > d:
		print('A')
	elif a < c and b < d:
		print('P')
	else:
		print('DRAW')