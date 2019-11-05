f = open('b013943.txt')
ans = 0
for i in range(9900):
	x, y = map(int, f.readline().split())
	if y % 2 == 1:
		ans += 1
print ans