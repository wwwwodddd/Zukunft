s = [0] + list(map(int, input().split()))
for i in range(1, 5):
	s[i] += s[i - 1]
for i in range(5):
	a = []
	for j in range(5):
		a.append(abs(s[i] - s[j]))
	print(*a)