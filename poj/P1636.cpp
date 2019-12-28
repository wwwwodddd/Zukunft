#include<stdio.h>
#include<string.h>
int a[410],b[410],f[210][210],h[410],m,n,p;
int F(int x)
{
	if(h[x]==x)
		return x;
	return h[x]=F(h[x]);
}
void U(int x,int y)
{
	h[F(x)]=F(y);
}
int main()
{
	int i,j,k;
	int t,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(i=1;i<=2*m;i++)
			h[i]=i;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			U(x,y+m);
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=1;i<=m;i++)
			a[F(i)]++,b[F(i+m)]++;
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(k=1;k<=2*m;k++)
			if(a[k]+b[k])
				for(i=m/2;i>=a[k];i--)
					for(j=m/2;j>=b[k];j--)
						if(f[i-a[k]][j-b[k]])
							f[i][j]=1;
		for(i=m/2;i>=0;i--)
			if(f[i][i])
			{
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}
