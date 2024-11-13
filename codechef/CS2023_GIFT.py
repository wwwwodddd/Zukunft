x, n, m = map(int, input().split())
print(['NO', 'YES'][x + m - n >= 0])