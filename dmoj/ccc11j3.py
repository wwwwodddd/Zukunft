a = [int(input()), int(input())]
while a[-2] >= a[-1]:
	a.append(a[-2] - a[-1])
print(len(a))