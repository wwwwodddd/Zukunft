#include<iostream>
#include<stack>
using namespace std;
struct N
{int r,v,p[4],u[4][2];}a[105];
int z[4][2],ans,cnt,n,t,p;
int find(int r)
{
	for(int i=0;i<n;i++)
		if(a[i].r==r)
			return i;
}
int dfs()
{
	stack<int>s;
	s.push(0);
	cnt=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<2;j++)
			z[i][j]=0;
	while(!s.empty())
	{
		p=s.top();
		s.pop();
		cnt++;
		a[p].v=1;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<2;j++)
				if(a[p].u[i][j])
				{
					int k=find(a[p].u[i][j]);
					if(a[k].v)
						continue;
					for(int g=0;g<4;g++)
						a[k].p[g]=a[p].p[g];
					if(a[k].u[i][1^j]==a[p].r)
					{
						if(j==0)
							a[k].p[i]--;
						else
							a[k].p[i]++;
						s.push(k);
					}
					else
						return -1;
				}
			z[i][0]=max(z[i][0],a[p].p[i]);
			z[i][1]=min(z[i][1],a[p].p[i]);
		}
	}
	if(cnt<n)
		return -1;
	else
	{
		int re=1;
		for(int i=0;i<4;i++)
			re*=(z[i][0]-z[i][1]+1);
		return re;
	}
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		memset(z,0,sizeof(z));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i].r);
			for(int j=0;j<8;j++)
				scanf("%d",a[i].u[0]+j);
		}
		ans=dfs();
		if(ans==-1)
			printf("Inconsistent\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}