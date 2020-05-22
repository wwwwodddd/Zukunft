a, b = map(int, raw_input().split())
print ['No', 'Yes'][a * b % 2]