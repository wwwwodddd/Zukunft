#include<stdio.h>
#include<string.h>
int i,j,z,l,r,u,v,n,m,k,x;
int a[105][10010],q[10010];
int b[10010],f[2][10010];
char s[2000000];
int max(int x,int y)
{
	return x>y?x:y;
}
int scan()
{
	int w=0,u=1;
	while(s[x]<'0'||s[x]>'9')x++;
	if(x&&s[x-1]=='-')u=-1;
	for(;s[x]>='0'&&s[x]<='9';x++)
		w=w*10+s[x]-'0';
	return w*u;
}
int main()
{
	while(scanf("%d %d %d",&n,&m,&k),n+m+k)
	{
		getchar();
		for(i=0;i<=n;i++)
		{
			gets(s);x=0;
			for(j=1;j<=m;j++) 
				a[i][j]=a[i][j-1]+scan();
		}
		memset(f,0,sizeof(f));
		for(i=0;i<=n;i++)
		{
			u=i&1;
			v=1^u;
			gets(s);x=0;
			for(j=1;j<=m;j++)
				b[j]=b[j-1]+scan();
			l=r=0;
			for(j=0;j<=m;j++)
			{
				while(l<r&&b[j]-b[q[l]]>k)l++;
				while(l<r&&f[v][q[r-1]]+a[i][j]-a[i][q[r-1]]<=f[v][j])r--;
				q[r++]=j;
				f[u][j]=f[v][q[l]]+a[i][j]-a[i][q[l]];
			}
			l=r=0;
			for(j=m;j>=0;j--)
			{
				while(l<r&&b[q[l]]-b[j]>k)l++; 
				while(l<r&&f[v][q[r-1]]+a[i][q[r-1]]-a[i][j]<=f[v][j])r--;
				q[r++]=j;
				f[u][j]=max(f[u][j],f[v][q[l]]+a[i][q[l]]-a[i][j]);
			}
		}
		for(z=i=0;i<=m;i++)
			z=max(z,f[u][i]);
		printf("%d\n",z);
	}
	return 0;
}