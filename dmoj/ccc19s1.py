s = input()
b = s.count('V') % 2 + s.count('H') % 2 * 2
print((0 ^ b) + 1, (1 ^ b) + 1)
print((2 ^ b) + 1, (3 ^ b) + 1)