f=open("PE42.txt","r")
a=eval("["+f.read()+"]")
c=[i*(i+1)/2 for i in range(50)]
z=0
for i in a:
	s=sum(map(lambda x:ord(x)-64,list(i)))
	if s in c:
		z+=1
print z
