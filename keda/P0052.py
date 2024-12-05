input()
a = list(map(int, input().split()))
x = int(input())
if x in a:
	print(a.index(x) + 1)
else:
	print(0)