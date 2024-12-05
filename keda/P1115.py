import datetime
y, m, d = map(int, input().split())
print((datetime.datetime(y, m, d) + datetime.timedelta(days=10000)).strftime('%Y-%-m-%-d'))