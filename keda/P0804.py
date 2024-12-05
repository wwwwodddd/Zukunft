import math
a, b, c, d = map(int, input().split())
print(10000 // math.lcm(a, b, c, d))