n = int(input())
a = sorted(map(int, input().split()))
print(sum(abs(i - a[n // 2]) for i in a))