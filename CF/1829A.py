t = int(input())
r = 'codeforces'
for tt in range(t):
	s = input()
	print(sum(x != y for x, y in zip(r, s)))