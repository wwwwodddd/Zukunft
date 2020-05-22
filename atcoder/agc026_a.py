input()
z = x = 0
for i in raw_input().split():
	if i == x:
		z += 1
		x = 0
	else:
		x = i
print z