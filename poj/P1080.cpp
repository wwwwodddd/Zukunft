#include<stdio.h>
#include<string.h>
int c[5][5]={{0,-3,-4,-2,-1},{-3,5,-1,-2,-1},{-4,-1,5,-3,-2},{-2,-2,-3,5,-2},{-1,-1,-2,-2,5}};
int a[105],b[105];
char ca[105],cb[105];
int f[105][105];
int i,j,t,la,lb;
int max(int x,int y)
{
	return x>y?x:y;
}
int F(int x,int y)
{
	if(f[x][y]!=0x80808080)
		return f[x][y];
	if(x==0&&y==0)
		return 0;
	int rx,ry,re;
	rx=ry=re=0x80808080;
	if(x!=0)
		rx=F(x-1,y)+c[a[x]][0];
	if(y!=0)
		ry=F(x,y-1)+c[0][b[y]];
	if(x!=0&&y!=0)
		re=F(x-1,y-1)+c[a[x]][b[y]];
	re=max(re,max(rx,ry));
	return f[x][y]=re;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0x80,sizeof(f));
		scanf("%d %s %d %s",&la,ca+1,&lb,cb+1);
		for(i=1;i<=la;i++)
			if(ca[i]=='A')
				a[i]=1;
			else if(ca[i]=='C')
				a[i]=2;
			else if(ca[i]=='G')
				a[i]=3;
			else if(ca[i]=='T')
				a[i]=4;
		for(i=1;i<=lb;i++)
			if(cb[i]=='A')
				b[i]=1;
			else if(cb[i]=='C')
				b[i]=2;
			else if(cb[i]=='G')
				b[i]=3;
			else if(cb[i]=='T')
				b[i]=4;
		printf("%d\n",F(la,lb));
	}
	return 0;
}