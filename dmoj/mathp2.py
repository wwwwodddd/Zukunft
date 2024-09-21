n = int(input())
p = 1000000007
print(sum(map(int, input().split())) * pow(2, n - 1, p) % p)