s=input()
if len(set(s[i*3:i*3+3]for i in range(len(s)//3)))!=len(s)//3:
	print('GRESKA')
else:
	print(13-s.count('P'),13-s.count('K'),13-s.count('H'),13-s.count('T'))