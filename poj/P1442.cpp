#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> >x;
priority_queue<int, vector<int>, less<int> >d;
int n,m,e;
int a[30020];
int main()
{
int i,j,k=1;
scanf("%d %d",&n,&m);
for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
for(j=1;j<=m;j++)
	{
	scanf("%d",&e);
	while(k!=e+1)
		x.push(a[k++]);
	while(d.size()<j)
		{
		d.push(x.top());
		x.pop();
		}
	while(!x.empty()&&d.top()>x.top())
		{
		x.push(d.top());
		d.push(x.top());
		x.pop();
		d.pop();
		}
	printf("%d\n",d.top());
	}
return 0;
}