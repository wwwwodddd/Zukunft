import copy
def fill():
	for _ in range(3):
		for i in range(3):
			if a[i][0] is None and a[i][1] is not None and a[i][2] is not None:
				a[i][0] = a[i][1] * 2 - a[i][2]
			if a[i][0] is not None and a[i][1] is None and a[i][2] is not None:
				if (a[i][0] + a[i][2]) % 2 != 0:
					return None
				a[i][1] = (a[i][0] + a[i][2]) // 2
			if a[i][0] is not None and a[i][1] is not None and a[i][2] is None:
				a[i][2] = a[i][1] * 2 - a[i][0]

		for i in range(3):
			if a[0][i] is None and a[1][i] is not None and a[2][i] is not None:
				a[0][i] = a[1][i] * 2 - a[2][i]
			if a[0][i] is not None and a[1][i] is None and a[2][i] is not None:
				if (a[0][i] + a[2][i]) % 2 != 0:
					return None
				a[1][i] = (a[0][i] + a[2][i]) // 2
			if a[0][i] is not None and a[1][i] is not None and a[2][i] is None:
				a[2][i] = a[1][i] * 2 - a[0][i]

a = []
for i in range(3):
	a.append(input().split())
	for j in range(3):
		if a[i][j] == 'X':
			a[i][j] = None
		else:
			a[i][j] = int(a[i][j])

fill()
for _ in range(4):
	if a[1][1] == None:
		a[1][1] = 0
		fill()
	if a[0][0] is None and a[0][2] is None and a[2][0] is None and a[2][2] is None:
		a[0][0] = 0
		fill()
	if a[0][0] is None and a[0][2] is not None:
		a[0][0] = a[0][2] % 2
		fill()
	if a[0][2] is None and a[2][0] is not None:
		a[0][2] = a[2][0] % 2
		fill()
	if a[2][0] is None and a[2][2] is not None:
		a[2][0] = a[2][2] % 2
		fill()
	if a[2][2] is None and a[0][0] is not None:
		a[2][2] = a[0][0] % 2
		fill()

for r in a:
	print(*r)
