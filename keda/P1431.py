n, m = map(int, input().split())
a = [list(map(float, input().split())) for i in range(n)]
x, y = map(int, input().split())
x -= 1
y -= 1
print('%.2f' % a[x][y])