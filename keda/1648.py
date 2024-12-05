import sys
sys.set_int_max_str_digits(10001)
a, b = map(int, input().split())
print(pow(a, b % 1000000006, 1000000007))