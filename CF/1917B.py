for t in range(int(input())):
	n = int(input())
	s = input()
	t = set()
	z = 0
	for i in s:
		t.add(i)
		z += len(t)
	print(z)