input()
a = list(map(int, input().split()))
b = list(map(int, input().split()))
for k, n in zip(b, a):
	if k == n:
		k = 0
	print(pow(2, k, 1000000007))