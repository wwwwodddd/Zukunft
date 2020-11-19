#include<stdio.h>
#include<string.h>
char s[1020][1020];
int a[1020],b[1020];
int n,m,x,y,i,j,z,tt,t;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		z=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			x--,y--;
			a[x]^=1;
			b[y]^=1;
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				z+=(a[i]+b[j]==1^s[i][j]=='w');
		printf("Case #%d: %d\n",++tt,z);
	}
	return 0;
}
