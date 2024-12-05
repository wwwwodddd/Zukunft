a, b, c = map(int, input().split())
print('%.3f' % (max(a, b, c) / (max(a + b, b, c) * max(a, b, b + c))))