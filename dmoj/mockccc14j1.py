a = int(input())
b = int(input())
r = int(input())
if a > r:
	print('Bob overdoses on day 1.')
elif a + 2 * b > 2 * r:
	print('Bob overdoses on day 2.')
else:
	print('Bob never overdoses.')