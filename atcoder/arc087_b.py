def F(a, d):
	s = set([0])
	for i in a:
		t = set([])
		for j in s:
			t.add(j - i)
			t.add(j + i)
		s = t
	return d in s
s = raw_input()
a = map(len, s.split('T'))
x, y = map(int, raw_input().split())
print ['No', 'Yes'][F(a[2::2], x - a[0]) and F(a[1::2], y)]