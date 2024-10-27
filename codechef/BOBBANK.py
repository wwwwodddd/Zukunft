t = int(input())
for tt in range(t):
	w, x, y, z = map(int, input().split())
	print(w + (x - y) * z)