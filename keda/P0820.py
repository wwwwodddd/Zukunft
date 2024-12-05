n = int(input())
a = [input() for i in range(n)]
s = input()
for i in sorted(a):
	if i.startswith(s):
		print(i)