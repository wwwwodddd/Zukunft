input()
z = s = 0
for i in map(int, raw_input().split())[::-1]:
	s ^= i
	z = z * 2 + s
print z