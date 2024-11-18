for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	print(min(min(a) * n + sum(b), min(b) * n + sum(a)))