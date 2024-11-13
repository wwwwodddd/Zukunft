n, q = map(int, input().split())
a = list(map(int, input().split()))
mn = min(a)
mx = max(a)
for i in range(q):
	print(['No', 'Yes'][mn <= int(input()) <= mx])