n, l, r = map(int, input().split())
if l // n != r // n:
	print(n - 1)
else:
	print(r % n)