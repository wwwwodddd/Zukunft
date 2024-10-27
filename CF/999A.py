n, k = map(int, input().split())
a = list(map(int, input().split()))
i = 0
j = n - 1
while i < n and a[i] <= k:
	i += 1
while i <= j and a[j] <= k:
	j -= 1
print(n - (j - i + 1))