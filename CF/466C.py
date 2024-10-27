n = int(input())
a = list(map(int, input().split()))
t = sum(a)
if t % 3:
	print(0)
else:
	t = t // 3
	f = [1, 0, 0]
	s = 0
	for i in a[:-1]:
		s += i
		for j in [2, 1]:
			if s == t * j:
				f[j] += f[j - 1]
	print(f[2])
