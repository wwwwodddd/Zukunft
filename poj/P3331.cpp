#include<stdio.h>
#include "string.h"
int n,w,m,t,k;
int a[10000],ans;
void mu(int x)
{
int i,j;
for(i=0;i<1000;i++)
	a[i]*=x;
for(i=0;i<1000;i++)
	{
	a[i+1]+=a[i]/10;
	a[i]%=10;
	}
return;
}
void ct(int x)
{
if(a[x]==n)
	ans++;
return;
}
int main()
{
int i,j;
freopen("C:\\c.in","r",stdin);
freopen("C:\\c1.out","w",stdout);
scanf("%d",&t);
while(t--)
	{
	ans=0;
	w=1;
	memset(a,0,sizeof(a));
	a[0]=1;
	scanf("%d %d",&m,&n);
	for(i=1;i<=m;i++)
		mu(i);
	k=999;
	while(!a[k])
		k--;
	for(i=0;i<=k;i++)
		ct(i);
	printf("%d\n",ans);
	}
return 0;
}