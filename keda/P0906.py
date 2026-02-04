s = input().strip()
t = input().strip()
z = 0
for i in s:
	z ^= ord(i)
for i in t:
	z ^= ord(i)
print(chr(z))
