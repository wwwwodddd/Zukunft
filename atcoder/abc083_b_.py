n,a,b=map(int,input().split())
print(sum(i*(a<=sum(int(j)for j in str(i))<=b) for i in range(n+1)))