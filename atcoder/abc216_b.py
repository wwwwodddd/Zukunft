n = int(input())
s = set(input() for i in range(n))
print(['Yes', 'No'][len(s) == n])