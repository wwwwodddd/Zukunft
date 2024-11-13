for t in range(int(input())):
	n = int(input())
	s = input()
	t = 0
	c = [0, 0]
	for i in s:
		c[t] += 1
		t ^= int(i)
	print(max(c))