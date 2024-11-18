c4, c7, c47, c74 = map(int, input().split())
z = -1
if c47 == c74 + 1 and c4 >= c47 and c7 >= c47:
	z = '4' * (c4 - c74) + '74' * c74 + '7' * (c7 - c74)
elif c47 + 1 == c74 and c4 >= c74 and c7 >= c74:
	z = '7' + '4' * (c4 - c47 - 1) + '47' * c47+ '7' * (c7 - c47 - 1) + '4'
elif c47 == c74 and c4 >= c47 + 1 and c7 >= c47:
	z = '4' * (c4 - c47 - 1) + '47' * (c47 - 1) + '4' + '7' * (c7 - c47 + 1) + '4'
elif c47 == c74 and c7 >= c74 + 1 and c4 >= c74:
	z = '7' + '4' * (c4 - c74) + '47' * c74 + '7' * (c7 - c74 - 1)
print(z)
