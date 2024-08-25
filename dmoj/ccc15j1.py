m = int(input())
d = int(input())
if (m, d) < (2, 18):
	print('Before')
elif (m, d) == (2, 18):
	print('Special')
else:
	print('After')