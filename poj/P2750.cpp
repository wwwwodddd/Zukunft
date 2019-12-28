#include<iostream>
#include<stdio.h>
using namespace std;
int s[400000];
int lm[400000];
int rm[400000];
int mx[400000];
int ln[400000];
int rn[400000];
int mn[400000];
int i,n,m,N,p,x,y,ans;
void mg(int z,int x,int y)
{
	mx[z]=max(max(mx[x],mx[y]),rm[x]+lm[y]);
	lm[z]=max(lm[x],s[x]+lm[y]);
	rm[z]=max(rm[y],s[y]+rm[x]);
	mn[z]=min(min(mn[x],mn[y]),rn[x]+ln[y]);
	ln[z]=min(ln[x],s[x]+ln[y]);
	rn[z]=min(rn[y],s[y]+rn[x]);
	s[z]=s[x]+s[y];
}
void ud(int x,int y)
{
	x+=N;
	for(ln[x]=rn[x]=mn[x]=lm[x]=rm[x]=mx[x]=s[x]=y;x>1;)
	{
		x>>=1;
		mg(x,x*2,x*2+1);
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for(N=n;N!=(N&-N);N+=N&-N);
	for(i=1;i<2*N;i++)
	{
		ln[i]=rn[i]=mn[i]=0x3fffffff;
		lm[i]=rm[i]=mx[i]=0xc0000000;
	}
	for(i=N+1;i<=N+n;i++)
	{
		scanf("%d",&s[i]);
		ln[i]=rn[i]=mn[i]=lm[i]=rm[i]=mx[i]=s[i];
	}
	scanf("%d",&m);
	for(i=N-1;i>0;i--)
		mg(i,i*2,i*2+1);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		ud(x,y);
		if(mx[1]==s[1])
			ans=s[1]-mn[1];
		else if(mn[1]==s[1])
			ans=mx[1];
		else
			ans=max(mx[1],s[1]-mn[1]);
		printf("%d\n",ans);
	}
	return 0;
}