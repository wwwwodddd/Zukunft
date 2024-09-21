a = int(input())
b = int(input())
c = int(input())
d = int(input())
z = 0
for i in range(101):
	for j in range(101):
		for k in range(101):
			if i * a + j * b + k * c <= d and i + j + k > 0:
				z += 1
				print(i, 'Brown Trout,', j, 'Northern Pike,', k, 'Yellow Pickerel')
print('Number of ways to catch fish:', z)