a = []
for i in range(4):
	a.append(list(map(int, input().split())))
def ok():
	s = sum(a[0])
	for i in range(4):
		if sum(a[i]) != s:
			return False
	b = list(zip(*a))
	for i in range(4):
		if sum(b[i]) != s:
			return False
	return True
print(['not magic', 'magic'][ok()])