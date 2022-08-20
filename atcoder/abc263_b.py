n = int(input())
p = [0, 0] + list(map(int, input().split()))
d = [0 for i in range(n + 1)]
for i in range(2, n + 1):
    d[i] = d[p[i]] + 1
print(d[n])
# x = n
# z = 0
# while x != 1:
#     x = p[x]
#     z += 1
# print(z)

