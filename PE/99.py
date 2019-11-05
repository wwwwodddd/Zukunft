import sys
import math
sys.stdin=open("PE99.txt","r")
mx=0
ans=0
for i in range(1000):
	a,b=map(int,raw_input().split(','))
	val=b*math.log(a)
	if val>mx:
		ans=i+1
		mx=val
print ans

