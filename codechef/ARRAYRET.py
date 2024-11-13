for t in range(int(input())):
	n = int(input())
	b = list(map(int, input().split()))
	s = sum(b) // (n + 1)
	print(*[i - s for i in b])