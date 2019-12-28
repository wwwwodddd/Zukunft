#include<iostream>
using namespace std;
const int MAXN =1510;
int t[2020][2];
int f[2020][2];
int v[2020];
int s[2020];
int n,m,i;
int x,y;
void F(int x)
{
	for(int i=t[x][0];i!=-1;i=t[i][1])
	{
		F(i);
		f[x][1]+=min(f[i][0],f[i][1]);
		f[x][0]+=f[i][1];
	}
	f[x][1]++;
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		memset(v,0,sizeof(v));
		memset(f,0,sizeof(f));
		memset(s,0,sizeof(s));
		memset(t,-1,sizeof(t));
		for(i=0;i<n;i++)
		{
			scanf("%d:(%d)",&x,&m);
			while(m--)
			{
				scanf("%d",&y);
				t[y][1]=t[x][0];
				t[x][0]=y;
				s[y]=1;
			}
		}
		for(i=0;i<n;i++)
			if(!s[i])
				x=i;
		F(x);
		printf("%d\n",min(f[x][1],f[x][0]));
	}
	return 0;
}