l, r = map(int, input().split())
z = [i for i in [153, 370, 371, 407] if l <= i <= r]
print(*z)