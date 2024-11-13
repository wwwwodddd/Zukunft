for t in range(int(input())):
	n = int(input())
	s = sum(map(int, input().split()))
	print(s * (s - 1) % 998244353)
