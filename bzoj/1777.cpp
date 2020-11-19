#include<stdio.h>
int n,m,l,x,y,z,a[10020];
int d[10020];
int main()
{
	scanf("%d %d %d",&n,&m,&l);
	for(int i=2;i<=n;i++)
	{
		scanf("%d %d",&x,a+i);
		a[i]%=l+1;
		d[i]=d[x]+1;
		if(d[i]&1)
			z^=a[i];
	}
	while(m--)
	{
		scanf("%d %d",&x,&y);
		if(d[x]&1)
		{
			z^=a[x];
			a[x]=y%(l+1);
			z^=a[x];
		}
		puts(z?"Yes":"No");
	}
	return 0;
}
