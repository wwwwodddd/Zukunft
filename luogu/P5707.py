s, v = map(int, input().split())
t = (470 - (s + v - 1) // v) % 1440
print('%02d:%02d' % (t // 60, t % 60))