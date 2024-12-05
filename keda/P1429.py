input()
a = input().split()
x, y = map(int, input().split())
print(*a[x - 1 : y])