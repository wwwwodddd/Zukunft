#include<stdio.h>
#include<math.h>
int l[105][60],d[105][3][105];
char a[105][105],f[105][60];
int c[105],s[3][105];
int n,i,j,k,t;
int color(int x,int y)
{
	c[x]=y;
	d[t][y][++d[t][y][0]]=x;
	for(int i=1;i<=n;i++)
		if(x!=i&&(!a[x][i]||!a[i][x]))
			if(c[i]==c[x])
				return printf("No solution\n");
			else if(c[i]==0&&color(i,3-y))
				return 1;
		return 0;
}
void print(int p,int x)
{
	if(p==0)
		return;	
	k=l[p][x];
	for(i=1;i<=d[p][k][0];i++)
		s[1][++s[1][0]]=d[p][k][i];
	for(i=1;i<=d[p][3-k][0];i++)
		s[2][++s[2][0]]=d[p][3-k][i];
	print(p-1,x-d[p][k][0]);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		while(1)
		{
		scanf("%d",&j);
	    if(!j)
			break;
		a[i][j]=1;
		}
	for(i=1;i<=n;i++)
		if(c[i]==0)
			{
			t++;
			if(color(i,1))
				return 0;
			}
	f[0][0]=1;
	for(i=1;i<=t;i++)
		for(j=0;j<=n/2;j++)
			if(f[i-1][j])
			{
				if(j+d[i][1][0]<=n/2)
				{
					f[i][j+d[i][1][0]]=1;
					l[i][j+d[i][1][0]]=1;
				}
				if(j+d[i][2][0]<=n/2)
				{
					f[i][j+d[i][2][0]]=1;
					l[i][j+d[i][2][0]]=2;
				}	
			}
	for(i=n/2;i>0;i--)
		if(f[t][i])
			break;
	print(t,i);
	for(i=0;i<=s[1][0];i++)
		printf("%d ",s[1][i]);
	printf("\n");
	for(i=0;i<=s[2][0];i++)
		printf("%d ",s[2][i]);
	printf("\n");
	return 0;
}