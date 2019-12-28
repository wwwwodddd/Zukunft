#include<iostream>
#include<queue>
using namespace std;
struct R
{
	int dt,t,n;
	bool operator < (const R &a) const
	{
		if(a.t==t)
			return a.n<n;
		return a.t<t;
	}
}x;
priority_queue<R>q;
int n,i;
char s[20];
int main()
{
	while(scanf("%s",s)&&s[0]!='#')
	{
		scanf("%d %d",&x.n,&x.dt);
		x.t=x.dt;
		q.push(x);
	}
	scanf("%d",&i);
	while(i--)
	{
		x=q.top();
		q.pop();
		printf("%d\n",x.n);
		x.t+=x.dt;
		q.push(x);
	}
}
