for t in range(int(input())):
	n = int(input())
	a = sorted(set(map(int, input().split())))
	print(a[-1] + a[-2])
