n = input()
a = [0 for i in range(1000)]
for i in range(n):
	s, t, b = map(int, raw_input().split())
	for j in range(s - 1, t):
		a[j] += b
print max(a)