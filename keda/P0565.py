n = int(input())
z = ''
a = list(map(int, input().split()))
for i in a:
	if a.count(z) < a.count(i):
		z = i
print(z)