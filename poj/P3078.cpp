#include<iostream>
using namespace std;
char s[25][20];
int n,m,t,i,j,x,y;
int v[25],z[25];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%s",s[i]);
		memset(v,0,sizeof(v));
		memset(z,-1,sizeof(z));
		while(m--)
		{
			scanf("%d%d",&x,&y);
			v[x]=1;
			z[y]=x;
		}
		for(i=j=1;i<=n;i++)
			if(z[i]==-1)
			{
				while(v[j])
					j++;
				z[i]=j;
				v[j]=1;
			}
		for(i=1;i<=n;i++)
			printf("%s ",s[z[i]]);
		printf("\n");
	}
	return 0;
}
