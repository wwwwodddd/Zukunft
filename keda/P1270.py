a = list(map(int, input().split()))
a.pop()
if len(a) & 1:
	print(a[len(a) // 2])
else:
	print(a[len(a) // 2] + a[len(a) // 2 - 1])
