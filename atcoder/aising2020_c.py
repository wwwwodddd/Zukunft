n = int(input())
z = [0 for i in range(n + 1)]
for i in range(1, 99):
	for j in range(1, 99):
		for k in range(1, 99):
			t = i * i + j * j + k * k + i * j + j * k + k * i
			if t <= n:
				z[t] += 1
for i in z[1:]:
	print(i)