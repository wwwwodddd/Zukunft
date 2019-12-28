#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[40020][3];
int p[20020];
int c[20020];
int t[20020];
int maxn;
int maxb;
int n;
int max(int a,int b)
{
return a>b?a:b;	
}
int min(int a,int b)
{
return a<b?a:b;	
}
int cmp(const void *a,const void *b)
{
if(((int *)a)[0]-((int *)b)[0]>0)
return 1;
else if(((int *)a)[0]-((int *)b)[0]<0)
return -1;
else
return (((int *)a)[1]-((int *)b)[1]);
}
int dfs(int x)
{
int i,mx=0,ds,sum=0;
for(i=c[x]-p[x];i<c[x];i++)
	if(t[a[i][1]]==0)	
	{
	t[a[i][1]]=1;
	ds=dfs(a[i][1]);
	sum+=ds;
	mx=max(mx,ds);
	}
if(max(mx,n-sum-1)<maxb||max(mx,n-sum-1)==maxb&&x<maxn)
{
maxb=max(mx,n-sum-1);
maxn=x;
}
return sum+1;
}
int main()
    {
    int i,j=0,k;
	scanf("%d",&k);
    while(k--)
	{
	memset(t,0,sizeof(t));
	memset(p,0,sizeof(p));
	memset(c,0,sizeof(c));
	scanf("%d",&n);
    for(i=0;i<2*n-2;i++)
        {
        scanf("%d %d",&a[i][0],&a[i][1]);
        a[i+1][0]=a[i][1];
		a[i+1][1]=a[i][0];
		a[i+1][2]=a[i][2];
        i++;
        }
    qsort(a,2*n-2,12,cmp);
    for(i=0;i<2*n-2;i++)
        p[a[i][0]]++;
    c[0]=p[0];
    for(i=1;i<n;i++)
        c[i]=c[i-1]+p[i];
	maxb=2147483647;
	t[1]=1;
    dfs(1);
	if(n==1)
		{
		maxb=0;
		maxn=1;
		}
	printf("%d %d\n",maxn,maxb);
	}
	return 0;
	}
