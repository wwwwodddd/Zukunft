for tt in range(int(input())):
	k = int(input())
	s = input()
	t = []
	a = []
	for i in range(len(s)):
		if s[i] == '(':
			t.append(i)
		else:
			a.append((i - t.pop()) // 2)
	a.sort()
	print(sum(a[:max(len(a)-k,0)]))