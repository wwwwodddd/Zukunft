a = [int(input())]
while a[-1] != 1:
	if a[-1] % 2 == 0:
		a.append(a[-1] // 2)
	else:
		a.append(a[-1] * 3 + 1)
print(*a)
