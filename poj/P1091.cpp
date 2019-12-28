#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int zs[11000];
int zsa[1500];
int n,m;
__int64 ans;
long long por(int x,int y)//x^y
    {
    int k;
    __int64 re;
    k=0;
    re=1;
    while(k<y)
        {
        k++;
        re=re*x;
        }
    return re;
    }
void dfs(int go,int i,int k,int kn)
    {
    int j,x;
    if(k==kn)
        {
        if(kn%2==0)
            x=1;
        else
            x=-1;
        for(j=i+1;j<=zsa[0];j++)
            ans+=x*por((m/(go*zsa[j])),n);
        return;
        }
    for(j=i+1;j<=zsa[0]-(kn-k);j++)
        dfs(go*zsa[j],j,k+1,kn);
    }
void work()
    {
	int sprt(int);
    int i,k,j,zcm;
    zs[1]=1;
    k=sqrtf(m);
    zcm=m;
    for(i=2;i<=k;i++)
        if(zs[i]==0)
            {
            for(j=2;j<=k/i;j++)
            zs[j*i]=1;
            if(zcm%i==0&&zcm!=0)
                {
                zsa[0]++;
                zsa[zsa[0]]=i;
                while(zcm%i==0)
                    zcm/=i;
                }
            }
    if(zcm>1)
        {
        zsa[0]++;
        zsa[zsa[0]]=zcm;
        }
    ans=por(m,n);
    for(i=1;i<=zsa[0];i++)
        {
        dfs(1,0,1,i);
        }
    printf("%I64d",ans);
}
int main()
    {
    scanf("%d %d",&n,&m);
    work();
    return 0;
    }