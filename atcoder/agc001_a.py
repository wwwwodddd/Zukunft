input()
a = sorted(map(int, raw_input().split()), reverse = True)
print sum(a[1::2])
