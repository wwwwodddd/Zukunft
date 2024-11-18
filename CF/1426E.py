n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
s = 0
t = 0
for i in range(3):
	s = max(s, a[i] + b[(i + 1) % 3] - n)
	t += min(a[i], b[(i + 1) % 3])
print(s, t)