#include<stdio.h>
int v[60];
int n,x,y,z,i,j,k,d,t;
int main()
{
	while(scanf("%d %d",&n,&x)+1)
	{
		printf("Selection #%d\n",++t);
		for(i=1;i<=n;i++)
			v[i]=1;
		y=n;
		for(i=1;i<=20;i++)
		{
			z=0;
			scanf("%d",&d);
			for(j=1;j<=n;j++)
				if(v[j])
				{
					z++;
					if(z%d==0)
						v[j]=0,y--;
					if(y==x)
					{
						for(k=1;k<=n;k++)
							if(v[k])
								printf("%d ",k);
							printf("\n\n");
						goto end;
					}
				}
		}
		end:
		for(i++;i<=20;i++)
			scanf("%d",&d);
	}
	return 0;
}
