import datetime
s = input()
print((datetime.datetime.strptime(s, '%Y-%m-%d')-datetime.datetime.strptime(s[:4], '%Y')).days+1)