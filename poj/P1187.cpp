#include<stdio.h>
#define F(k,x) for(k=0;k<=x;k++)
int f[31][11][11][11];
int dp(int d,int a,int b,int c)
{
int i,j,k;
int r=0;
if(a==0&&b==0&&c==0)
	return 1;
if(c!=0)
	F(i,c-1)
		r=(r+f[d][a][b][c-i-1]*f[d-1][0][0][i])%11380;
if(b!=0)
	F(i,b-1)
		F(j,c)
			r=(r+f[d][a][b-i-1][c-j]*f[d-1][0][i][j])%11380;
if(a!=0)
	F(i,a-1)
		F(j,b)
			F(k,c)
				r=(r+f[d][a-i-1][b-j][c-k]*f[d-1][i][j][k])%11380;
return r;
}
int main()
	{
	int l1,l2,l3,d,i,j,k,l;
	scanf("%d %d %d %d",&l1,&l2,&l3,&d);
	f[0][0][0][0]=1;
	for(i=1;i<=d;i++)
		F(j,l1)
			F(k,l2)
				F(l,l3)
					f[i][j][k][l]=dp(i,j,k,l)%11380;
	if(d!=0)
		printf("%d",(f[d][l1][l2][l3]-f[d-1][l1][l2][l3]+11380)%11380);
	else
		printf("%d",f[d][l1][l2][l3]);
	return 0;
}