n, m, x, y = map(int, raw_input().split())
x = max(x, *map(int, raw_input().split()))
y = min(y, *map(int, raw_input().split()))
print ['War', 'No War'][x < y]