n = int(input())
a = map(int, input().split())
l = 0
z = 0
for i in a:
	if l < i:
		l = i
	z += l - i
print(z)