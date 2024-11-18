for t in range(int(input())):
	n = int(input())
	s = sum(map(int, input().split()))
	print(s % 2, min(s, 2 * n - s))
