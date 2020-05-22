x, y = map(int, raw_input().split())
print ['Alice', 'Brown'][abs(x - y) < 2]