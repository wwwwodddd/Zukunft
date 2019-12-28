#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
priority_queue<long long>q;
long long d[100020],ans;
long long h;
int a,b,c;
int main()
{
	scanf("%I64d %d %d %d",&h,&a,&b,&c);
	memset(d,0x3f,sizeof d);
	d[0]=0;
	q.push(0);
	for(;q.size();)
	{
		long long u=-q.top(),v,w;
		q.pop();
		if(d[u%a]!=u)
			continue;
		v=u+b,w=v%a;
		if(d[w]>v)
			d[w]=v,q.push(-v);
		v=u+c,w=v%a;
		if(d[w]>v)
			d[w]=v,q.push(-v);
	}
	for(int i=0;i<a;i++)
		if(h>d[i])
			ans+=(h-d[i]+a-1)/a;
	printf("%I64d\n",ans);
	return 0;
}
