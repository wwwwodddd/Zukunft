input()
x = sum(map(int, input().split()))
y = sum(map(int, input().split()))
if x > y:
	print('ke')
elif x < y:
	print('da')
else:
	print('tie')