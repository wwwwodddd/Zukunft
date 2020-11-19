#include<stdio.h>
int w[100020];
int f[100020];
int s[100020],ss;
int n,m,x,y;
int F(int x)
{
	int i;
	ss=0;
	while(f[x]!=x)
	{
		s[ss++]=x;
		x=f[x];
	}
	for(i=0;i<ss;i++)
		f[s[i]]=x;
	return x;
}
void U(int x,int y)
{
	if(F(x)==F(y))
		w[x]=1;
	f[F(x)]=F(y);
}
int main()
{
	int i;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		f[i]=i;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		U(x,y);
	}
	for(i=1;i<=n;i++)
		if(w[i])
			w[F(i)]=1;
	for(i=1;i<=n;i++)
		if(!w[F(i)])
			break;
	puts(i>n?"TAK":"NIE");
	return 0;
}