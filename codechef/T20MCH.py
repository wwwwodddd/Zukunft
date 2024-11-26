r, o, c = map(int, input().split())
print(['NO', 'YES'][r < (20 - o) * 36 + c])