#include<stdio.h>
#include<string.h>
int x,y,t,n,m,i,j;
int a[20],b[20],f[100020];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		scanf("%d %d %d",&x,&n,&m);
		y=x/10;
		for(i=0;i<m;i++)
		{
			scanf("%d %d",a+i,b+i);
			a[i]/=1000;
			for(j=a[i];j<y;j++)
				if(f[j]<f[j-a[i]]+b[i])
					f[j]=f[j-a[i]]+b[i];
		}
		for(i=0;i<n;i++)
			x+=f[x/1000];
		printf("%d\n",x);
	}
	return 0;
}