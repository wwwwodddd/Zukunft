t = int(input())
for tt in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	print(min(min(a) * max(a), min(map(abs, a)) ** 2), max(max(a) ** 2, min(a) ** 2))