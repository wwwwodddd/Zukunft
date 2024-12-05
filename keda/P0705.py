import sys
sys.set_int_max_str_digits(10001)
n, m = map(int, sys.stdin.read().split())
print((n + m) * (m - n + 1) // 2)