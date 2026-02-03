for t in range(int(input())):
	n = int(input())
	z, zi = 0, 0
	for i in range(n):
		t, d = map(int, input().split())
		if z < t // d:
			z = t // d
			zi = i + 1
	print(zi)
