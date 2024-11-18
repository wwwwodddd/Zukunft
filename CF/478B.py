n, m = map(int, input().split())
print(n // m * (n // m - 1) // 2 * (m - n % m) + n // m * (n // m + 1) // 2 * (n % m), (n - m + 1) * (n - m) // 2)