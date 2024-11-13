for t in range(int(input())):
	s = 21 - sum(map(int, input().split()))
	if 1 <= s <= 10:
		print(s)
	else:
		print(-1)
