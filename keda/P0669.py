n = input()
a = list(map(int, input().split()))
b = sorted(a)
print(sum(x!=y for x,y in zip(a,b)))