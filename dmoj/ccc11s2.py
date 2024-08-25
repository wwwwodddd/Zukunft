n = int(input())
a = [input() for i in range(n)]
b = [input() for i in range(n)]
print(sum(a[i] == b[i] for i in range(n)))