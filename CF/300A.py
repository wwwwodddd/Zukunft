n = int(input())
a = sorted(map(int, input().split()))
print(1, a[0])
if a[-1] > 0:
	print(1, a[-1])
	print(n - 2, *a[1:-1])
else:
	print(2, a[1], a[2])
	print(n - 3, *a[3:])