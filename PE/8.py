s=""
for i in range(10):
	s+=raw_input()
z=0
for i in range(len(s)-4):
	z=max(z,int(s[i])*int(s[i+1])*int(s[i+2])*int(s[i+3])*int(s[i+4]))
#	print int(s[i])*int(s[i+1])*int(s[i+2])*int(s[i+3])*int(s[i+4])
print z

