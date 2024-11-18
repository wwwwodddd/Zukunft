for t in range(int(input())):
	n = int(input())
	s = input()
	z = 0
	for i in set(s):
		if s.count(i) >= ord(i) - 64:
			z += 1
	print(z)