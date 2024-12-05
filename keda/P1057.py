import datetime
d, m, y = map(int, input().split())
print(["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"][datetime.datetime(y,m,d).weekday()])