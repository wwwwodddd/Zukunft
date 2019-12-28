#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int n,m,c,i,j,k;
int ok,z,now,u;
int v[100],a[100];
int main()
{
	while(scanf("%d%d%d",&n,&m,&c)&&n+m+c)
	{
		u=now=0;
		ok=1;
		memset(v,0,sizeof(v));
		for(i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		for(i = 1;i <= m;i++)
		{
			scanf("%d",&z);
			now-=v[z]*a[z];
			v[z]=v[z]^1;
			now+=v[z]*a[z];
			if(now>c)
				ok=0;
			if(now>u)
				u=now;
			
		}
		printf("Sequence %d\n",++k);
		if(ok)
			printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",u);
		else
			printf("Fuse was blown.\n\n");
	}
	return 0;
}
