h = int(input())
m = int(input())
for t in range(1, m + 1):
	if -6 * t * t * t * t + h * t * t * t + 2 * t * t + t <= 0:
		print('The balloon first touches ground at hour:')
		print(t)
		break
else:
	print('The balloon does not touch ground in the given time.')