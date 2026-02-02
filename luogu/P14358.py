n, m = map(int, input().split())
a = list(map(int, input().split()))
c = 0
for i in a:
	if i > a[0]:
		c += 1
x = c // n
y = c % n
if x % 2:
	y = n - y - 1
print(x + 1, y + 1)