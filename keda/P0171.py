input()
a = [i for i in map(int, input().split()) if i % 2]
print(*reversed(a), sep=',')