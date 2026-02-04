n = int(input())
a = list(map(int, input().split()))
mxa = max(a)
mna = min(a)
if mxa == mna:
	print(0, n * (n - 1) // 2)
else:
	print(mxa - mna, a.count(mxa) * a.count(mna))