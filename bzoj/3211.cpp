#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
long long s[400020];
int l[400020];
int r[400020];
int f[400020];
int N,n,i,j,k,m;
int x,y,z,o,csc;
void pd(int idx)
{
	if(idx>=N)
	{
		s[idx]=(long long)sqrt((double)s[idx]);
		if(s[idx]<2)
			f[idx]=1;
		return;
	}
	if(f[idx]==r[idx]-l[idx]+1)
		return;
	pd(idx*2);
	pd(idx*2+1);
	s[idx]=s[idx*2]+s[idx*2+1];
	f[idx]=f[idx*2]+f[idx*2+1];
}
long long qy(int idx)
{
	if(x<=l[idx]&&y>=r[idx])
		return s[idx];
	if(x>r[idx]||y<l[idx])
		return 0;
	return qy(idx*2)+qy(idx*2+1);
}
void ud(int idx)
{
	if(x<=l[idx]&&y>=r[idx])
	{
		pd(idx);
		return;
	}
	if(x>r[idx]||y<l[idx])
		return;
	ud(idx*2);
	ud(idx*2+1);
	s[idx]=s[idx*2]+s[idx*2+1];
	f[idx]=f[idx*2]+f[idx*2+1];
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		memset(s,0,sizeof(s));
		for(N=n;N!=(N&(-N));N+=(N&(-N)));
		for(i=N;i<N+n;i++)
		{
			scanf("%lld",&s[i]);
			if(s[i]<2)
				f[i]=1;
		}
		for(i=N;i<N*2;i++)
			r[i]=l[i]=i-N+1;
		for(i=N-1;i>0;i--)
		{
			s[i]=s[i*2]+s[i*2+1];
			f[i]=f[i*2]+f[i*2+1];
			l[i]=l[i*2];
			r[i]=r[i*2+1];
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&o);
			scanf("%d %d",&x,&y);
			if(x>y)
				swap(x,y);
			if(o==1)
				printf("%lld\n",qy(1));
			else
				ud(1);
		}
		printf("\n");
	}
	return 0;
}
