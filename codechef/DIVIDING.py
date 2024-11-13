n = int(input())
print(['NO', 'YES'][sum(map(int, input().split())) == n * (n + 1) // 2])
