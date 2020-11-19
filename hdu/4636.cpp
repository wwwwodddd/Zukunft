#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[60];
int k,t,b,f;
void add(int x,int y)
{
	a[x].push_back(y);
	a[y].push_back(x);
}
int A(int s,int a,int b,int c,int d,int e)
{
	add(s,a),add(s,b),add(s,c),add(s,d),add(s,e);
	add(a,b),add(b,c),add(c,d),add(d,e),add(e,a);
}
int q[10000],d[100],c[100];
int calc(int x)
{
	b=f=100;
	q[f++]=x;
	memset(d,-1,sizeof d);
	d[x]=0;
	for(;b<f;)
	{
		int u=q[b++];
		fe(i,a[u])
			if(d[*i]==-1)
				if(c[*i]==c[u])
					d[*i]=d[u],q[--b]=*i;
				else
					d[*i]=d[u]+1,q[f++]=*i;
	}
	int u=*max_element(d+1,d+33);
	u+=c[x]+u&1;
	return u;
}
int main()
{
	A(3,1,2,4,5,20);
	A(7,2,4,8,10,12);
	A(6,4,5,24,9,8);
	A(11,8,9,27,16,10);
	A(13,1,2,12,15,17);
	A(14,16,10,12,15,30);
	A(18,17,19,22,20,1);
	A(21,22,20,5,24,25);
	A(23,19,22,25,28,31);
	A(26,25,24,9,27,28);
	A(29,16,30,31,28,27);
	A(32,17,19,31,30,15);
	for(scanf("%d",&t);t--;)
	{
		for(int i=1;i<=32;i++)
			scanf("%d",c+i);
		int z=32;
		for(int i=1;i<=32;i++)
			z=min(z,calc(i));
		printf("Case %d: %d\n",++k,z);
	}
}
