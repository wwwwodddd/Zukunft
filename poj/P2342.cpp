#include<stdio.h>
int v[6020];
int d[6020][2];
int n,i,x,y,r=1;
int max(int x,int y)
{
	return x>y?x:y;
}
int F(int x,int &z)
{
	int i,r,o=0;
	z=0;
	if(d[x][0]==0)
		return max(0,v[x]);
	for(i=d[x][0];i!=0;i=d[i][1])
		z+=F(i,r),o+=r;
	return max(z,o+v[x]);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		d[x][1]=d[y][0];
		d[y][0]=x;
		if(r==x)
			r=y;
	}
	printf("%d",F(r,i));
	return 0;
}