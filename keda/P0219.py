n = int(input())
a = list(map(int, input().split()))
ax = max(a)
print(sum(i for i in a if i < ax))