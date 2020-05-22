a, b, c = map(int, raw_input().split())
s = max(a, b, c) * 3 - a - b - c
s += s % 2 * 3
print s / 2