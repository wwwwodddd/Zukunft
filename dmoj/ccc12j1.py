x = int(input())
y = int(input())
if y - x <= 0:
	print('Congratulations, you are within the speed limit!')
elif y - x <= 20:
	print('You are speeding and your fine is $100.')
elif y - x <= 30:
	print('You are speeding and your fine is $270.')
else:
	print('You are speeding and your fine is $500.')
