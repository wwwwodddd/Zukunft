#include<stdio.h>
typedef long long ll;
int a[203][203];
int b[203][203];
int n,m,p=1000000007;
inline int mul(int a,int b,int mod)
{
	int ans = 0;
	__asm__ __volatile__ (
	"movl %1,%%eax\n\t"
	"mull %2\n\t"
	"divl %3"
	: "=d"(ans)
	: "m"(a),"m"(b),"m"(mod)
	: "%eax"
	);
	return ans;
}
void mul(int a[203][203],int b[203][203],int c[203][203])
{
	int w[203][203]={};
	for(int i=0;i<m+2;i++)
		for(int k=0;k<m+2;k++)
			for(int j=0;j<m+2;j++)
				if(a[i][k])
					w[i][j]=(w[i][j]+mul(a[i][k],b[k][j],p))%p;
	for(int i=0;i<m+2;i++)
		for(int j=0;j<m+2;j++)
			c[i][j]=w[i][j];
}
int main()
{
	scanf("%d%d",&n,&m);
	a[0][0]=1;
	b[m][m+1]=1;
	b[m+1][m+1]=1;
	for(int i=0;i<=m;i++)
	{
		b[0][i]=m;
		for(int j=1;j<=i;j++)
			b[j][i]=(b[j][i-1]+b[j-1][i-1])%p;
	}
	for(n++;n;n>>=1)
	{
		if(n&1)
			mul(a,b,a);
		mul(b,b,b);
	}
	printf("%d",a[0][m+1]);
	return 0;
}
