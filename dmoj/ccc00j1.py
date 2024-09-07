d, n = map(int, input().split())
print('Sun Mon Tue Wed Thr Fri Sat')
s = ['   '] * (d - 1) + ['%3d' % i for i in range(1, n + 1)]
for i in range(0, len(s), 7):
	print(*s[i : i + 7])