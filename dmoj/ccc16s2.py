t = int(input())
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
a.sort()
b.sort(reverse=(t > 1))
z = 0
for i in range(n):
	z += max(a[i], b[i])
print(z)