n = int(input())
a = []
for i in range(n):
    x, y = map(int, input().split())
    a.append([x, y])
z = 0
for i in range(n):
    for j in range(i):
        if abs(a[j][1]-a[i][1]) <= abs(a[j][0]-a[i][0]):
            z += 1
print(z)