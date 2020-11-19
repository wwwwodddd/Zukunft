#include<iostream>
#include<string.h>
#include<stdio.h>
#define la (2*N+1)
#define ra (2*N+3)
using namespace std;
long long s[600000];
long long lm[600000];
long long rm[600000];
long long mx[600000];
long long cp;
int i,n,m,k,d,N,p,x,y;
void mg(int z,int x,int y)
{
	mx[z]=max(max(mx[x],mx[y]),rm[x]+lm[y]);
	lm[z]=max(lm[x],s[x]+lm[y]);
	rm[z]=max(rm[y],s[y]+rm[x]);
	s[z]=s[x]+s[y];
}
void clr(int x)
{
	lm[x]=rm[x]=mx[x]=0xcccccccc;
	s[x]=0;
}
int qy(int l,int r)
{
	clr(0);
	clr(la);
	clr(ra);
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)
			mg(la,la,l^1);
		if(r&1)
			mg(ra,r^1,ra);
	}
	mg(0,la,ra);
	return mx[0];
}
void ud(int x,int y)
{
	x+=N;
	for(lm[x]=rm[x]=mx[x]=s[x]=s[x]+y;x>1;)
	{
		x>>=1;
		mg(x,x*2,x*2+1);
	}
	return;
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&k,&d);
	cp=k;
	cp*=d;
	for(N=n;N!=(N&-N);N+=N&-N);
	memset(lm,0,sizeof(lm));
	memset(rm,0,sizeof(rm));
	memset(mx,0,sizeof(mx));
	for(i=N;i<N+n;i++)
	{
		lm[i]=rm[i]=mx[i]=s[i]=-k;
	}
	for(i=N-1;i>0;i--)
		mg(i,i*2,i*2+1);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		ud(x-1,y);
		puts(mx[1]>cp?"NIE":"TAK");
	}
	return 0;
}