l, r = map(int, input().split())
r = r // 2
l = (l - 1) // 2
print(r * (r + 1) - l * (l + 1))