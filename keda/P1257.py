n, m = map(int, input().split())
s = 0
for i in sorted(map(int, input().split()))[:m]:
	if i < 0:
		s -= i
print(s)