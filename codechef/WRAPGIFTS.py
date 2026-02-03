for t in range(int(input())):
	h, l, w = map(int, input().split())
	s = (h * l + l * w + w * h) * 2
	print(1000 // s)
