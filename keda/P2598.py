n,k=map(int,input().split())
a=sorted([-1]+[int(input())//12for i in range(n)])
z=a[-1]+1-sum(sorted([y-x-1for x,y in zip(a,a[1:])])[-k+1:])
print(z*12)