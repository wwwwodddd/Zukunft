#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int mo=1000000001;
int q[400],p[30],c,n,l;
int f[1050],g[1050];
long long ans=1;
int work(int x)
{
    memset(f,0,sizeof f);
    f[0]=1;
    for(int i=0; x >> i > 0; i++)
    {
        swap(f, g);
        memset(f,0,sizeof f);
        for(l=0;p[l]<=x>>i;l++)
            ;
        for(int j=0;j<c;j++)
            if(g[j])
                for(int k=0;q[k]<1<<l;k++)
                    if((q[j]&q[k])==0)
                        f[k]=(f[k]+g[j])%mo;
    }
    return f[0]+f[1];
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=1<<12;i++)
        if((i&i<<1)==0)
            q[c++]=i;
    for(int i=p[0]=1;i<13;i++)
        p[i]=p[i-1]*3;
    for(int i=1;i<=n;i++)
        if(i%2&&i%3)
            ans=ans*work(n/i)%mo;
    printf("%lld",ans);
    return 0;
}