n = int(input())
a = [i for i in [3, 5, 7] if n % i == 0]
if len(a) == 0:
	a = ['n']
print(*a)