#include<iostream>
using namespace std;
int r[500020],n,s;
int t[500020][30];
int f[500020];
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
void uni(int x,int y)
{
	f[F(x)]=F(y);
}
int ins(char *p)
{
	int z=0,k;
	for(;*p;p++)
	{
		k=*p-'a';
		if(t[z][k]==-1)
			t[z][k]=++s;
		z=t[z][k];
	}
	if(t[z][26]==-1)
		t[z][26]=n++;
	return t[z][26];
}
int check()
{
	int i,re=0;
	for(i=1;i<n;i++)
		re+=r[i]&1;
	if(re>2)
		return 0;
	re=F(1);
	for(i=2;i<n;i++)
		if(F(i)!=re)
			return 0;
	return 1;
}
int main()
{
	char p[15],q[15];
	int i,a,b;
	memset(t,-1,sizeof(t));
	n=1;
	s=0;
	for(i=1;i<500020;i++)
		f[i]=i;
	while(scanf("%s%s",p,q)+1)
	{
		a=ins(p);
		r[a]++;
		b=ins(q);
		r[b]++;
		uni(a,b);
	}
	if(check())
		puts("Possible");
	else
		puts("Impossible");
	return 0;
}
