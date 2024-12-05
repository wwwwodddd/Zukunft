import datetime
y1, m1, d1 = map(int, input().split())
y2, m2, d2 = map(int, input().split())
print((datetime.datetime(y2, m2, d2) - datetime.datetime(y1, m1, d1)).days)