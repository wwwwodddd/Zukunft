#include<iostream>
using namespace std;
int n,p,t[160][2],f[160][160],i,x,y;
void D(int x)
{
	int i,j,k;
	f[x][1]=0;
	for(i=t[x][0];i;i=t[i][1])
		D(i),f[x][1]++;
	for(i=t[x][0];i;i=t[i][1])
		for(k=p-1;k>0;k--)
			for(j=1;j+k<=p;j++)
				f[x][k+j]=min(f[x][k+j],f[x][k]+f[i][j]-1);
}
int main()
{
	scanf("%d %d",&n,&p);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		t[y][1]=t[x][0];
		t[x][0]=y;
	}
	memset(f,0x3f,sizeof(f));
	D(1);
	y=f[1][p];
	for(i=2;i<=n;i++)
		y=min(y,f[i][p]+1);
	printf("%d\n",y);
	return 0;
}
