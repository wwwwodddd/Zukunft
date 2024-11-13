for t in range(int(input())):
	n = int(input())
	s = sum(map(int, input().split()))
	print(min(s, n - s))