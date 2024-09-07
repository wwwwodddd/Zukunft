a, b, c, d = map(int, input().split())
if a < b and c < d:
	print('Go to the department store')
elif a < b:
	print('Go to the grocery store')
elif c < d:
	print('Go to the pharmacy')
else:
	print('Stay home')