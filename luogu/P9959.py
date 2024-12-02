n = int(input())
a = list(map(int, input().split()))
for i in range(n)[::-1]:
	if i == 0 or a[i-1] > a[i]:
		print(i)
		break
