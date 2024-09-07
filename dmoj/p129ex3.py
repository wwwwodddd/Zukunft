n = int(input())
b = 0
while n > 1 << b:
	b += 1
print(b)