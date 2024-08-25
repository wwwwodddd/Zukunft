n, t = map(int, input().split())
a = list(map(int, input()))
for i in range(50):
	if t >> i & 1:
		a = [a[(j - (1 << i)) % n] ^ a[(j + (1 << i)) % n] for j in range(n)]
print(''.join(map(str, a)))