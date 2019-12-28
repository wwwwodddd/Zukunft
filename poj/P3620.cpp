#include<stdio.h>
int n,m,i,j,k,x,y,c;
int a[105][105];
int s(int x,int y)
{
if(a[x][y]==1)
{
a[x][y]=0;
return s(x,y+1)+s(x-1,y)+s(x+1,y)+s(x,y-1)+1;
}
return 0;
}

int main()
{
scanf("%d %d %d",&n,&m,&k);
while(k--)
	{
	scanf("%d %d",&x,&y);
	a[x][y]=1;
	}
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(a[i][j]==1)
            {
            k=s(i,j);
			c<k?c=k:0;
			}
printf("%d",c);
return 0;
}