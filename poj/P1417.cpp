#include<stdio.h>
#include<string.h>
int f[1220],same[1220],diff[1220];
int dp[605][605],c[605][605],d[605][605];
int v[605];
int n,p1,p2,m,x,y,i,j,k,l;
char ch[5];
int F(int x)
{
	return x==f[x]?x:f[x]=F(f[x]);
}
void U(int x,int y)
{
	f[F(y)]=F(x);
}
void D()
{
	memset(v,0,sizeof(v));
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	l=0;
	for(i=1;i<=m;i++)
		if(!v[i])
		{
			v[i]=1;
			x=0;
			y=0;
			for(j=1;j<=m;j++)
				if(F(same[i])==F(same[j]))
				{
					v[j]=1;
					x++;
				}
				else if(F(same[i])==F(diff[j]))
				{
					v[j]=1;
					y++;
				}
			l++;
			for(j=x;j<=p1;j++)
				if(dp[l-1][j-x]>0)
				{
					dp[l][j]+=dp[l-1][j-x];
					d[l][j]=j-x;
					c[l][j]=i;
				}
			for(j=y;j<=p1;j++)
				if(dp[l-1][j-y]>0)
				{
					dp[l][j]+=dp[l-1][j-y];
					d[l][j]=j-y;
					c[l][j]=-i;
				}
		}
	return;
}
void print()
{
	memset(v,0,sizeof(v));
	j=p1;
	do
	{
		k=c[l][j];
			for(i=1;i<=m;i++)
				if((k>0&&F(same[i])==F(same[k]))||(k<0&&F(same[-k])==F(diff[i])))
					v[i]=1;
		j=d[l][j];
		l--;
	}
	while(l!=0);
	for(i=1;i<=m;i++)
		if(v[i])
			printf("%d\n",i);
	puts("end");
}
int main()
{
	while(scanf("%d %d %d",&n,&p1,&p2)&&n+p1+p2)
	{
		m=p1+p2;
		for(i=1;i<=m*2;i++)
			f[i]=i;
		for(i=1;i<=m;i++)
		{
			same[i]=i;
			diff[i]=i+m;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d %d %s",&x,&y,ch);
			if(ch[0]=='y')
			{
				U(same[x],same[y]);
				U(diff[x],diff[y]);
			}
			else if(ch[0]=='n')
			{
				U(same[x],diff[y]);
				U(diff[x],same[y]);
			}
		}
		D();
		if(dp[l][p1]==1)
			print();
		else
			puts("no");
	}
}
