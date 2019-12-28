#include<iostream>
int n,f[2020];
int F(int x)
{
	if(x<0)
		return 0;
	if(f[x]!=-1)
		return f[x];
	int i,v[2020]={0};
	for(i=1;i<=x;i++)
		v[F(i-2-1)^F(x-i-2)]=1;
	for(i=0;i<=n;++i)
		if(!v[i])
			return f[x]=i;
}
int main()
{
	memset(f,-1,sizeof(f));
	scanf("%d",&n);
	printf("%d",2-(bool)F(n));
	return 0;
}