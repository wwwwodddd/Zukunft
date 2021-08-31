k=int(input())
a,b=map(int,input().split())
print('NOGK'[(a-1)//k<b//k::2])
