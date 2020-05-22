x, y = map(int, raw_input().split())
print ['Even', 'Odd'][x * y % 2]