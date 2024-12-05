input()
a = list(map(int, input().split()))
try:
	print(a.index(int(input())) + 1)
except:
	print(0)