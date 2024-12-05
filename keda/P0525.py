h, r = map(int, input().split())
v = r * r * 3.1415926535 * h / 1000
print(int(20 // v + 1))