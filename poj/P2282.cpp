#include<stdio.h>
int n,m,ans;
int f[15][10];
int p[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int fc(int x,int d,int t)
{
if(t==0)
	return x<d?0:1;
if(x<d)
	return f[t-1][d]*x;
else
	return f[t-1][d]*x+p[t];
}
int main()
{
int i,j,k;
for(i=1;i<9;i++)
	f[0][i]=1;
for(j=1;j<10;j++)
	for(i=1;i<9;i++)
		f[j][i]=10*f[j-1][i]+p[j];
while(scanf("%d %d",&m,&n)&&m!=0&&n!=0)
{
m--;
for(k=0;k<10;k++)
{
ans=0;
for(i=0;m>=p[i];i++)
	ans-=fc(m/p[i]%10,k,i);
for(i=0;n>=p[i];i++)
	ans+=fc(n/p[i]%10,k,i);
printf("%d ",ans);
}
printf("\n");
}
return 0;
}