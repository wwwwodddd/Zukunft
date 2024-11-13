for t in range(int(input())):
	n = int(input())
	a = sorted(map(int, input().split()))
	print(sum(a[n//2:]) - sum(a[:n//2]))
