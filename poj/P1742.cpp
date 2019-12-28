#include<stdio.h>
#include<string.h>
int a[100010];
int t[100010];
int b[120];
int c[120];
int main()
{
int m,n,ans;
int i,j,k;
while(scanf("%d %d",&n,&m)&&n!=0&&m!=0)
{
ans=0;
memset(a,0,sizeof(a));
a[0]=1;
for(i=0;i<n;i++)
	scanf("%d",&b[i]);
for(i=0;i<n;i++)
	scanf("%d",&c[i]);
for(i=0;i<n;i++)
	{
	memset(t,0,sizeof(t));
	for(j=0;j<=m;j++)
		if(a[j]&&t[j]<c[i]&&j+b[i]<=m&&a[j+b[i]]==0)
		{
		a[j+b[i]]=1;
		t[j+b[i]]=t[j]+1;
		}
	}
for(i=m;i>0;i--)
	ans+=a[i];
printf("%d\n",ans);
}
return 0;
}