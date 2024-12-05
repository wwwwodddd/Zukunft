n = int(input())
a = list(map(int, input().split()))
print(*[i + 1 for i in range(n) if a[i] == i + 1])