a = [0, 100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000]
n = int(input())
s = sum(a)
for i in range(n):
	s -= a[int(input())]
m = int(input())
if m * (10 - n) > s:
	print('deal')
else:
	print('no deal')