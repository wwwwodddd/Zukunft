#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[420][420],ans;
int m,t,d=350,n=377;
int q[200000][2],b[420];
int v[10];
int i,j,k,x,y,z,sum;
int min(int a,int b)
{
	return a<b?a:b;
}
int bfs()//n to n+1
{
	int h=0,t=1;
	q[0][0]=n;
	q[0][1]=2147483647;
	int i,k;
	memset(b,-1,sizeof(b));
	b[n]=0x3fffffff;
	while(h<t)
	{
		for(i=0;i<=n+1;i++)
			if(a[q[h][0]][i]>0&&b[i]==-1&&i!=q[h][0])
			{
				q[t][0]=i;
				q[t][1]=min(q[h][1],a[q[h][0]][i]);
				b[i]=q[h][0];
				if(b[n+1]>=0)
				{
					k=n+1;
					ans+=q[t][1];
					while(b[k]!=0x3fffffff)
					{
						a[b[k]][k]-=q[t][1];
						a[k][b[k]]+=q[t][1];
						k=b[k];
					}
					return 1;
				}
				t++;
			}
		h++;
	}
	return 0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		ans=sum=0;
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			for(j=0;j<7;j++)
				scanf("%d",&v[j]);
			scanf("%d %d",&x,&y);
			for(j=0;j<7;j++)
				if(v[j])
					for(k=0;k<y;k++)
						a[d+i][7*k+j]=1;
			a[n][d+i]=x;
			sum+=x;
		}
		for(i=0;i<350;i++)
			a[i][n+1]=1;
		while(bfs());
		if(ans==sum)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}