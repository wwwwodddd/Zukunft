n = int(input())
a = input().split()
b = input().split()
x = y = 0
for i in range(n):
	if a[i] == 'rock' and b[i] == 'paper' or a[i] == 'paper' and b[i] == 'scissors' or a[i] == 'scissors' and b[i] == 'rock':
		y += 1
	if b[i] == 'rock' and a[i] == 'paper' or b[i] == 'paper' and a[i] == 'scissors' or b[i] == 'scissors' and a[i] == 'rock':
		x += 1
print(x, y)