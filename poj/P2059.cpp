#include<stdio.h>
#include<string.h>
int i,j,k,m,n,r,t,z;
int a[60][2];
int g[60][60];
int min(int x,int y)
{
	return x<y?x:y;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(g,0,sizeof(g));
		scanf("%d %d",&m,&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&a[i][0],&a[i][1]);
			g[a[i][0]][a[i][1]]=1;
		}
		for(i=1;i<m;i++)
			for(j=1;j<m;j++)
			{
				if(g[i][j])
					continue;
				r=min(min(i*i,(m-i)*(m-i)),min(j*j,(m-j)*(m-j)));
				for(k=0;k<n;k++)
					if((i-a[k][0])*(i-a[k][0])+(j-a[k][1])*(j-a[k][1])>r)
						break;
				if(k==n)
					goto end;
			}
		end:
		if(i==m&&j==m)
			printf("poodle\n");
		else
			printf("%d %d\n",i,j);
	}
	return 0;
}