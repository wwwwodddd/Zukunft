n,k=map(int,input().split())
a=list(map(int,input().split()))
print(sum((min(i,n-k)-max(i-k+1,0)+1)*a[i]for i in range(n)))