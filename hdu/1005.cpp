/*
  Name: 
  Copyright: 
  Author: 
  Date: 29-12-11 22:13
  Description: 
*/
// juzhen chengfa
// qing ling 
// keyi zhao zhouqi
#include<string.h>
#include<stdio.h>
int a[5][5];
int b[5][5];
void mul(int x[5][5],int y[5][5],int z[5][5])
{
	int re[5][5];
	memset(re,0,sizeof(re));
	int i,j,k;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			for(k=0;k<2;k++)
				re[i][j]=(re[i][j]+x[i][k]*y[k][j])%7;
	memcpy(z,re,sizeof(re));
}
void pw(int x[5][5],int y,int z[5][5])
{
	int re[5][5];
	int i;
	memset(re,0,sizeof(re));
	for(i=0;i<2;i++)
		re[i][i]=1;
	while(y)
	{
		if(y&1)
			mul(re,x,re);
		mul(x,x,x);
		y>>=1;	
	}
	memcpy(z,re,sizeof(re));
	return;
}
int csc;
int main()
{
	int n,x,y;
	while(scanf("%d %d %d",&x,&y,&n),x+y+n)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		if(n==1||n==2)
		{
			printf("1\n");	
			continue;
		}
		n--;
		a[0][0]=1;
		a[0][1]=1;
		b[1][0]=1;
		b[0][1]=y;
		b[1][1]=x;
		pw(b,n,b);
		mul(a,b,a);
		printf("%d\n",a[0][0]);
	}
	return 0;
}
