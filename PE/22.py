import sys
sys.stdin=open("PE22.txt","r")
s='['+raw_input()+']'
s=sorted(eval(s))
def F(q):
	return sum(map(lambda i:ord(i)-64,list(q)))
z=0

#print s.index("COLIN")
#print s[937]
#print F(s[937])
for i in range(len(s)):
	z+=(i+1)*F(s[i])
print z
