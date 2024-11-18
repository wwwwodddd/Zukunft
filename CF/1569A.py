for t in range(int(input())):
	n = int(input())
	s = input()
	for i in range(1, len(s)):
		if s[i - 1] != s[i]:
			print(i, i + 1)
			break
	else:
		print(-1, -1)