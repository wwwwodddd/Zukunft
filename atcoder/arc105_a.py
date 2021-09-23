a,b,c,d=sorted(list(map(int,input().split())))
print('YNeos'[a+b+c!=d and b+c!=a+d::2])