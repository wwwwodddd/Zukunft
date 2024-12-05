s = input().strip()
z = 0
t = 0
for i in s:
	if i == 'A':
		t += 1
	else:
		t -= 1
	if t == 0:
		z += 1
print(z)