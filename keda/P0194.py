s = set()
for i in range(int(input())):
	s.add(input())
for i in range(int(input())):
	n = input()
	if n in s:
		print(n)