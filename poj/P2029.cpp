#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int c[220][220];
int ans;
int n,x,y,w,h,s,t;
int i,j;
int max(int x,int y)
{
	return x>y?x:y;
}
void R(int x,int y,int v)
{
	for(int i=x;i<=h;i+=(i&(-i)))
		for(int j=y;j<=w;j+=(j&(-j)))
			c[i][j]+=v;
}
int G(int x,int y)
{
	int q=0;
	for(int i=x;i>0;i-=(i&(-i)))
		for(int j=y;j>0;j-=(j&(-j)))
			q+=c[i][j];
	return q;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		scanf("%d %d",&h,&w);
		memset(c,0,sizeof(c));
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			R(x,y,1);
		}
		ans=0;
		scanf("%d %d",&s,&t);
		for(i=s;i<=h;i++)
			for(j=t;j<=w;j++)
				ans=max(ans,G(i,j)+G(i-s,j-t)-G(i-s,j)-G(i,j-t));
		printf("%d\n",ans);
	}
	return 0;
}

