def f(x):
	return x * x + 2 * x + 3
t = int(input())
print(f(f(f(t)+t)+f(f(t))))