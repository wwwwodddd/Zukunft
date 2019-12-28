#include<iostream>
#include<queue>
using namespace std;
int ans[1024];
int t,n,i,j;
queue<int>q;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=n;i>0;i--)
		{
			q.push(i);
			for(j=1;j<=i;j++)
			{
				q.push(q.front());
				q.pop();
			}
		}
		for(i=n;i>0;i--)
		{
			ans[i]=q.front();
			q.pop();
		}
		for(i=1;i<=n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
