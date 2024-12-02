n = int(input())
a = list(map(int, input().split()))
def F(s):
	b = [s]
	for i in range(len(a)):
		b.append(a[i] - b[i])
	if len(set(b)) == n and max(b) == n and min(b) == 1:
		return ' '.join(map(str, b))
	return None
for i in range(1, n):
	if F(i):
		print(F(i))