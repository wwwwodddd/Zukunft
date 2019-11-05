from re import *
suf=[]
for i in xrange(100000):
	if i*i%10==9 and i*i/100%10==8 and i*i/10000%10==7:
		suf.append(i*10)
for i in xrange(1010000000,1389026623,1000000): 
	for j in suf:
		print (i+j)*(i+j)
		if match("1.2.3.4.5.6.7.8.9.0",str((i+j)*(i+j))):
			print i+j
			raw_input()

