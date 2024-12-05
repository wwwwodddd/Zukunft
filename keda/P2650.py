import sys
sys.set_int_max_str_digits(100001)
a, b = map(int, sys.stdin.read().split())
print((a + b) * 2)