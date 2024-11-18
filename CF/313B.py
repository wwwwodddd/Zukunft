s = ' ' + input()
t = [0]
for i in range(1, len(s)):
	t.append(t[-1] + (s[i] == s[i - 1]))
for i in range(int(input())):
	x, y = map(int, input().split())
	print(t[y] - t[x])