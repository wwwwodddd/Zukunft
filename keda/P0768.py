s = input()
t = input()
if s == t:
	print(2)
elif s.lower() == t.lower():
	print(3)
elif len(s) == len(t):
	print(4)
else:
	print(1)