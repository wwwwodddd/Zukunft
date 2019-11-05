a = 1801088541
b = 558545864083284007
c = 35831808
p = 10 ** 9
ans = (b * (b + 1) / 2 - (b + 1) * c)
cnt = b + 1;
cnt += a * (b / a) * (b / a - 1) / 2 + (b % a + 1) * (b / a)
ans += cnt * (4 * a - 3 * c)
print ans % p