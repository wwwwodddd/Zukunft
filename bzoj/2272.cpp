#include<stdio.h>
#define fr(i,n) for(int i=0;i<n;i++)
int f[252][252][52];
int a[220],b[220];
char s[5];
int u,l,p,z;
int C(char c)
{
	if('A'<=c&&c<='Z')
		return c-'A';
	return c-'a'+26;
}
int main()
{
	scanf("%d %d %d",&u,&l,&p);
	fr(i,p)
	{
		scanf("%s",s);
		a[i]=C(s[0]),b[i]=C(s[1]);
	}
	fr(i,26)
		f[1][0][i]=f[0][1][i+26]=1;
	fr(i,u+1)
		fr(j,l+1)
			fr(k,p)
				if(b[k]<26)
					f[i+1][j][b[k]]=(f[i+1][j][b[k]]+f[i][j][a[k]])%97654321;
				else
					f[i][j+1][b[k]]=(f[i][j+1][b[k]]+f[i][j][a[k]])%97654321;
	fr(i,52)
		z=(z+f[u][l][i])%97654321;
	printf("%d\n",z);
}
