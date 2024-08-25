n = int(input()) + 1
while len(set(str(n))) < len(str(n)):
	n += 1
print(n)