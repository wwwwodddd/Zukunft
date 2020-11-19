#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
const int N=103;
int a[N][N];
int b[30][N][N];
int d[N][N];
int p=1000000007;
struct C
{
	int n,a[103];
}c[103];
bool operator<(const C&a,const C&b)
{
	return a.n<b.n;
}
int r[103],f[103];
int k,t,T,n,m,q,nn;
inline int mul(int a,int b)
{
	int ans = 0;
	__asm__ __volatile__ (
	"movl %1,%%eax\n\t"
	"mull %2\n\t"
	"divl %3"
	: "=d"(ans)
	: "m"(a),"m"(b),"m"(p)
	: "%eax"
	);
	return ans;
}
int mul(int a[N][N],int b[N][N],int c[N][N])
{
	long long _[N][N]={};
	for(int i=0;i<T;i++)
		for(int k=0;k<T;k++)
			if(a[i][k])
				for(int j=0;j<T;j++)
					_[i][j]+=mul(a[i][k],b[k][j]);
	for(int i=0;i<T;i++)
		for(int j=0;j<T;j++)
		{
			if(_[i][j]>=p)
				_[i][j]%=p;
			c[i][j]=_[i][j];
		}
	return 0;
}
bool cmp(const C&x,const C&y)
{
	return x.n<y.n;
}
void cal(int x)
{
	for(int i=0;x>>i;i++)
		if(x>>i&1)
			mul(a,b[i],a);
}
int main()
{
	for(;~scanf("%d %d %d",&n,&m,&q);)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(d,0,sizeof d);
		for(int i=0;i<m;i++)
			scanf("%d",f+i);
		scanf("%d",&t);
		T=t;
		for(int i=0;i<t;i++)
			scanf("%d",r+i);
		for(int i=0;i<q;i++)
		{
			int t;
			scanf("%d %d",&c[i].n,&t);
			if(T<t)
				T=t;
			for(int j=0;j<t;j++)
				scanf("%d",c[i].a+j);
		}
		nn=m;
		for(int i=0;i<min(m,T);i++)
			a[0][T-1-i]=f[m-1-i];
		for(int i=1;i<T;i++)
			b[0][i][i-1]=1;
		for(int i=0;i<t;i++)
			b[0][T-1-i][T-1]=r[i];
		sort(c,c+q);
		for(int i=1;1<<i<n;i++)
			mul(b[i-1],b[i-1],b[i]);
		for(int i=0;i<q;i++)
		{
			if(c[i].n>n)
				break;
			for(int j=0;j<T;j++)
				for(int k=0;k<T;k++)
					d[j][k]=0;
			for(int j=1;j<T;j++)
				d[j][j-1]=1;
			for(int j=0;j<T;j++)
				d[T-1-j][T-1]=c[i].a[j];
			cal(c[i].n-nn-1);
			mul(a,d,a);
			nn=c[i].n;
		}
		cal(n-nn);
		printf("Case %d: %d\n",++k,a[0][T-1]);
	}
	return 0;
}
