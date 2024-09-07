for t in range(int(input())):
	i, s = input().split(' ', 1)
	i = int(i)
	print(t + 1, s[:i-1] + s[i:])
