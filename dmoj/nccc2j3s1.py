n = int(input())
a = [int(input()) for i in range(n)]
print(min(sum(a) // 2, sum(a) - max(a)))