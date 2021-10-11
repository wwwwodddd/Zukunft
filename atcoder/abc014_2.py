n,x=map(int,input().split())
a=list(map(int,input().split()))
print(sum(a[i]for i in range(n)if x>>i&1))