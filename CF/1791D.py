for t in range(int(input())):
	n = int(input())
	s = input()
	t = set()
	f = [0]
	for i in s:
		t.add(i)
		f.append(len(t))
	t = set()
	z = 0
	for i in range(n)[::-1]:
		t.add(s[i])
		z = max(z, len(t) + f[i])
	print(z)