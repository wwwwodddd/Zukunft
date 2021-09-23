a,b=map(lambda x:abs(int(x)),input().split())
print(['Draw','Bug','Ant'][(a>b)-(a<b)])