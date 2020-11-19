#include<stdio.h>
int f[300],v[300],t,n,x;
int F(int x)
{
	if(x<87)
		return f[x];
	return f[(x-87)%34+87];
}
int main()
{
	for(int i=2;i<121;i++)
	{
		for(int j=0;j<i-1;j++)
			v[f[j]^f[i-j-2]]=i;
		for(;v[f[i]]==i;)
			f[i]++;
	}
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		int z=0;
		for(int i=0;i<n;i++)
			scanf("%d",&x),z^=F(x);
		puts(z?"Carol":"Dave");
	}
}
