a = [28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65]
print('%.1f' % sum(x * y for x, y in zip(a, map(int, input().split()))))