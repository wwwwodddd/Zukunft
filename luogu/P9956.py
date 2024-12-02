n = int(input())
a = list(map(int, input().split()))
cnt = 0
for i in range(n):
	for j in range(i + 1, n + 1):
		if sum(a[i:j]) % (j-i) == 0 and sum(a[i:j]) // (j-i) in a[i:j]:
			cnt += 1
print(cnt)