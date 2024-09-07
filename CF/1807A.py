t = int(input())
for tt in range(t):
	a, b, c = map(int, input().split())
	if a + b == c:
		print('+')
	else:
		print('-')