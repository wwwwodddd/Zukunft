a, b, c = map(int, input().split())
print(['No', 'Yes'][a * a + b * b == c * c])