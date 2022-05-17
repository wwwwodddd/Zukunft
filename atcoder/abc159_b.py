s=input()
t=s[:len(s)//2]
if s!=s[::-1] or t!=t[::-1]:
	print('No')
else:
	print('Yes')