n, l = map(int, input().split())
a = list(map(int, input().split()))
a.sort(reverse=True)
for i in range(1, n + 1):
	if a[i - 1] < i:
		j = i - 1
		while j >= 0 and l > 0:
			a[j] += 1
			l -= 1
			j -= 1
		break
z = 0
a.sort(reverse=True)
for i in range(1, n + 1):
	if a[i - 1] >= i:
		z = i
	else:
		break
print(z)