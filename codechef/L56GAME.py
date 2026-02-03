for t in range(int(input())):
	n = int(input())
	s = sum(map(int, input().split()))
	if n == 1 or s % 2 == 0:
		print(1)
	else:
		print(2)
