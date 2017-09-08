import datetime
a,b = map(int, input().split())
t = datetime.datetime(100, 1, 1, a, b, 0) + datetime.timedelta(minutes = -45)
print(t.hour, end=' ')
print(t.minute)