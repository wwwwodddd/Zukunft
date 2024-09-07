n = int(input())
a = sorted(map(int, input().split()))
b = []
for i in range(n):
	if i & 1:
		b.append(a[(n + 1) // 2 + i // 2])
	else:
		b.append(a[(n - 1) // 2 - i // 2])
print(*b)