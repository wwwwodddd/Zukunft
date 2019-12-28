#include<iostream>
using namespace std;
char c[120][120];
int n,m,i,j,k,x,y,dx,dy,mx,ans,l,r,u,b;
int main()
{
	memset(c,1,sizeof(c));
	scanf("%d %d %d",&n,&m,&k);
	while(k--)
	{
		scanf("%d %d %d %d",&x,&y,&dx,&dy);
		l=max(1,y-dx/2);
		r=min(m,y+dx/2);
		u=max(1,x-dx/2);
		b=min(n,x+dx/2);
		for(i=u;i<=b;i++)
			for(j=l;j<=r;j++)
				if(!dy)
					c[i][j]=0;
				else
					c[i][j]++;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(c[i][j]>mx)
				mx=c[i][j],ans=1;
			else if(c[i][j]==mx)
				ans++;
	printf("%d\n",ans);
	return 0;
}