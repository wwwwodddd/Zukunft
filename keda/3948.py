n, m = map(int, input().split())
print(sum(m % i == 0 for i in map(int, input().split())))