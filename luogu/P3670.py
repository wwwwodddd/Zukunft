import sys
sys.stdin = open('cownomics.in', 'r')
sys.stdout = open('cownomics.out', 'w')
n, m = map(int, input().split())
a = []
b = []
z = 0
def func(c):
	if c == 'A':
		return 0
	elif c == 'C':
		return 1
	elif c == 'G':
		return 2
	elif c == 'T':
		return 3
for i in range(n):
	a.append([func(i) for i in input()])
for i in range(n):
	b.append([func(i) for i in input()])
v = [0 for i in range(64)]
c = 0
for i in range(m):
	for j in range(i):
		for k in range(j):
			c += 1
			for t in a:
				h = (t[i]) * 16 + (t[j]) * 4 + (t[k])
				v[h] = c
			for t in b:
				h = (t[i]) * 16 + (t[j]) * 4 + (t[k])
				if v[h] == c:
					break
			else:
				z += 1
print(z)