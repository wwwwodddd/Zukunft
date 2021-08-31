a,b=map(int,input().split())
print([b-a,b+a][b%a==0])