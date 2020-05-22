n = input()
a = map(int, raw_input().split())
x = (sum(a) + len(a) / 2) / len(a)
print sum((i - x) ** 2 for i in a)