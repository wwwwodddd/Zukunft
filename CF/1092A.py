for t in range(int(input())):
	n, k = map(int, input().split())
	print((''.join(map(chr, range(97, 97 + k)))*n)[:n])