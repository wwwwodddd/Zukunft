for t in range(int(input())):
	w, x, y, z = map(int, input().split())
	print(['NO', 'YES'][w in {x, y, z, x + y, y + z, z + x, x + y + z}])
