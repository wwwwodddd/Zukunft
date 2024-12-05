a, b, c, d = map(int, input().split())
z = c * 60 + d - a * 60 - b
print(z // 60, z % 60)