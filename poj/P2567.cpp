#include<iostream>
#include<stack>
using namespace std;
int f[1020],v[1020],a[1020];
char c[1020];
int main()
{
	while(gets(c))
	{
		stack<int>s;
		int n=0;
		memset(f,-1,sizeof(f));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		int i,j,x;
		int m=strlen(c);
		for(i=0;i<m-1;i++)
		{
			if(c[i]=='(')
			{
				x=0;
				i++;
				while(c[i]>='0'&&c[i]<='9')
				{
					x=x*10+c[i]-'0';
					i++;
				}
				i--;
				n=max(n,x);
				s.push(x);
			}
			else if(c[i]==')')
			{
				x=s.top();
				s.pop();
				f[x]=s.top();
				a[s.top()]++;
			}
		}
		for(i=0;i<n-1;i++)
		{
			x=100000;
			for(j=1;j<n;j++)
				if(!v[j]&&(a[j]==0||(f[j]==-1&&a[j]==1)))
					x=min(x,j);
			v[x]=1;
			if(f[x]==-1)
				for(j=1;j<=n;j++)
				{
					if(v[j]==0&&f[j]==x)
					{
						f[j]=-1;
						printf("%d ",j);
						break;
					}
				}
			else if(a[x]==0)
			{
				a[f[x]]--;
				printf("%d ",f[x]);
			}
		}
		cout<<endl;
	}
	return 0;
}