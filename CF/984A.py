n = int(input())
a = sorted(map(int, input().split()))
print(a[(len(a) - 1) // 2])