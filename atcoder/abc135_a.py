a,b=map(int,input().split())
print([a+b>>1,'IMPOSSIBLE'][a+b&1])