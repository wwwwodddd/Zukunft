a,b=map(int,input().split())
print([0,b//2,b][min((a+1)//7,2)])