n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
s = (sum(a) + sum(b)) * 3
for i in range(1, n):
	if a[i] == a[i - 1] == 1:
		s -= 2
	if b[i] == b[i - 1] == 1:
		s -= 2
for i in range(0, n, 2):
	if a[i] == b[i] == 1:
		s -= 2
print(s)