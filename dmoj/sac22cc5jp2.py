n = int(input())
s = 0
for i in range(n):
	x, y = map(int, input().split())
	if x > y:
		s += 1
print(s)