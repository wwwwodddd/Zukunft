for t in range(int(input())):
	n, d = input().split()
	s = input()
	for i in range(len(s)):
		if d > s[i]:
			print(s[:i] + d + s[i:])
			break
	else:
		print(s + d)
