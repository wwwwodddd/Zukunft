s = input()
t = 'HONI'
j = 0
for i in s:
	if i == t[j % 4]:
		j += 1
print(j // 4)