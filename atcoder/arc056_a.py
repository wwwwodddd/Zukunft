a, b, k, l = map(int, raw_input().split())
print k / l * b + min(k % l * a, b)