n = int(input())
a = list(map(int, input().split()))
s = sum(a)
print(sum(n * i > s for i in a))
