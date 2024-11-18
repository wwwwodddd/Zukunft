for t in range(int(input())):
	n = int(input())
	a = [0] + [i for i in map(int, input().split()) if i != 0]
	s = sum(abs(i) for i in a)
	z = sum(1 for i in range(1, len(a)) if a[i - 1] >= 0 and a[i] < 0)
	print(s, z)