input()
s = input()
a = [1] * s.count('n') + [0] * s.count('z')
print(*a)