for t in range(int(input())):
	n = int(input())
	s = sum(map(int, input().split()))
	if s > 0:
		print(0)
	else:
		print(-(s // n))