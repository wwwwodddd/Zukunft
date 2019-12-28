#include <iostream>
using namespace std;
int n;
int s[51000];
long long t[4][50020];
int x[50];
struct L
{
	int v,p;
}l[51000];
long long G(int x,long long *c)
{
	long long q=0;
	for(int i=x;i>0;i-=(i&(-i)))
		q+=c[i];
	return q;
}
void R(int x,long long v,long long *c)
{
	for(int i=x;i<=n;i+=(i&(-i)))
		c[i]+=v;
}
int cmp(const void *a,const void *b)
{
	return((L*)a)->v-((L*)b)->v;
}
void H()
{
	int i,j=1;
	for(i=0;i<n;i++)
	{
		l[i].v=s[i];
		l[i].p=i;
	}
	qsort(l,n,sizeof(L),cmp);
	s[l[0].p]=1;
	for(i=1;i<n;i++)
	{
		if(l[i].v!=l[i-1].v)
			j++;
		s[l[i].p]=j;
	}
}
void P(long long k)
{
	int i;
	long long t=k,c;
	for(i=1;k;i++)
	{
		x[i]+=k%10;
		k/=10;
	}
	for(i=1;i<40;i++)
	{
		x[i+1]+=x[i]/10;
		x[i]%=10;
	}
}
void dp()
{
	int i,j,k;
	memset(t,0,sizeof(t));
	for(k=0;k<n;k++)
	{
		for(j=1;j<4;j++)
			R(s[k],G(s[k]-1,t[j-1]),t[j]);
		R(s[k],1,t[0]);
		P(G(s[k]-1,t[3]));
	}
}
void final()
{
	x[0]=40;
	while(!x[x[0]]&&x[0])
		x[0]--;
	for(int i=x[0];i>1;i--)
		printf("%d",x[i]);
	printf("%d\n",x[1]);
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&s[i]);
		H();
		memset(x,0,sizeof(x));
		dp();
		final();
	}
	return 0;
}