a, b, c = map(int, input().split())
print(max(a + b, b + c, c + a))
print(a + b + c - min(a, b, c))

a = list(map(int, input().split()))
print(sum(a) - min(a))

a = sorted(map(int, input().split()))
print(a[1] + a[2])

