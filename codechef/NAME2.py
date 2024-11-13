for t in range(int(input())):
	s, t = input().split()
	if len(s) > len(t):
		s, t = t, s
	i = 0
	for c in t:
		if i < len(s) and s[i] == c:
			i += 1
	print(['NO', 'YES'][i == len(s)])