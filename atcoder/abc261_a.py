l1, r1, l2, r2 = map(int, input().split())
print(max(min(r1, r2) - max(l1, l2), 0))