input()
a=list(map(int,input().split()))
n=sum(i>0 for i in a)
print((sum(a)+n-1)//n)