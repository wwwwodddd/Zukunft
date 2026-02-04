input()
a = list(map(int, input().split()))
s = sum(a)
t = 0
for i in range(len(a)):
	s -= a[i]
	if s == t:
		print(i)
		break
	t += a[i]
else:
	print(-1)