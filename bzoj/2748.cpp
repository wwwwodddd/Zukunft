#include<stdio.h>
int f[1020],g[1020],l,x,n;
int main()
{
	scanf("%d%d%d",&n,&x,&l);
	f[x]=1;
	while(n--)
	{
		scanf("%d",&x);
		for(int j=0;j<=l;j++)
			if(f[j])
				j-x>=0&&g[j-x]++,j+x<=l&&g[j+x]++;
		for(int j=0;j<=l;j++)
			f[j]=g[j],g[j]=0;
	}
	for(;~l&&!f[l];)
		l--;
	printf("%d",l);
	return 0;
}
