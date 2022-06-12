for t in range(int(input())):
	n = int(input())
	a = map(int, input().split())
	s = sum(i for i in a if i % 2)
	print(max(s, sum(a) - s))
