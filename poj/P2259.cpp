#include<iostream>
#include<string>
#include<queue>
using namespace std;
int i,j,t,n,m,x,v[1020];
int r[1000020];
char s[20];
queue<int>q[1020];
queue<int>p;
int main()
{
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
		{
			v[i]=0;
			while(q[i].size())
				q[i].pop();
		}
		while(p.size())
			p.pop();
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&x);
				r[x]=i;
			}
		}
		printf("Scenario #%d\n",++t);
		while(scanf("%s",s),s[0]!='S')
		{
			if(s[0]=='E')
			{
				scanf("%d",&x);
				if (!v[r[x]])
				{
					v[r[x]]=1;
					p.push(r[x]);
				}
				q[r[x]].push(x);
			}
			else if(s[0]=='D')
			{
				x=p.front();
				printf("%d\n",q[x].front());
				q[x].pop();
				if(q[x].empty())
				{
					p.pop();
					v[x]=0;
				}
			}
		}
		printf("\n");
	}
	return 0;
}