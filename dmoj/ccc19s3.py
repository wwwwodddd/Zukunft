import copy
empty = 123896123612936192873912873891273
def dfs(a): # a is 3x3 array
	# print(a)
	changed = True
	while changed:
		changed = False
		for i in range(3):
			if a[i][0] == empty and a[i][1] != empty and a[i][2] != empty:
				a[i][0] = a[i][1] * 2 - a[i][2]
				changed = True
			if a[i][0] != empty and a[i][1] == empty and a[i][2] != empty:
				if (a[i][0] + a[i][2]) % 2 != 0:
					return None
				a[i][1] = (a[i][0] + a[i][2]) // 2
			if a[i][0] != empty and a[i][1] != empty and a[i][2] == empty:
				a[i][2] = a[i][1] * 2 - a[i][0]
				changed = True
			if a[i][0] != empty and a[i][1] != empty and a[i][2] != empty:
				if a[i][0] + a[i][2] != 2 * a[i][1]:
					return None

		for i in range(3):
			if a[0][i] == empty and a[1][i] != empty and a[2][i] != empty:
				a[0][i] = a[1][i] * 2 - a[2][i]
				changed = True
			if a[0][i] != empty and a[1][i] == empty and a[2][i] != empty:
				if (a[0][i] + a[2][i]) % 2 != 0:
					return None
				a[1][i] = (a[0][i] + a[2][i]) // 2
			if a[0][i] != empty and a[1][i] != empty and a[2][i] == empty:
				a[2][i] = a[1][i] * 2 - a[0][i]
				changed = True
			if a[0][i] != empty and a[1][i] != empty and a[2][i] != empty:
				if a[0][i] + a[2][i] != 2 * a[1][i]:
					return None

	x = -1
	y = -1
	for i in range(3):
		for j in range(3):
			if a[i][j] == empty:
				x = i
				y = j
	if x == -1 and y == -1:
		return a
	assert x != -1 and y != -1
	# find last -1
	for k in range(6):
		b = copy.deepcopy(a)
		b[x][y] = k
		r = dfs(b)
		if r is not None:
			return r
	return None

a = []
for i in range(3):
	a.append(input().split())
	for j in range(3):
		if a[i][j] == 'X':
			a[i][j] = empty
		else:
			a[i][j] = int(a[i][j])

b = dfs(a)

for r in b:
	print(*r)
