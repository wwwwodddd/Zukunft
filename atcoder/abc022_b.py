n = int(input())
print(n - len(set(input() for i in range(n))))