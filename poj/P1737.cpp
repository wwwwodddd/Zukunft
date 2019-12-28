#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
int f[52][800];
int a[800],b[800],c[800],d[800];
int er[52][800];
int e[52];
int n;
void smul(int *a,int x)
{
	int i;
	int c[800];
	memset(c,0,sizeof(c));
	c[0]=a[0];
	for(i=1;i<=a[0];i++)
		c[i]+=a[i]*x;
	for(i=1;i<=c[0];i++)
	{
		c[i+1]+=c[1]/10;
		c[i]%=10;
	}
	while(c[c[0]+1])
		c[0]++;
	memcpy(a,c,sizeof(c));
	return;
}
void dmul(int *a,int *b)
{
	int i,j;
	int c[800];
	memset(c,0,sizeof(c));
	c[0]=a[0]+b[0];
	for(i=1;i<=a[0];i++)
		for(j=1;j<=b[0];j++)
			c[i+j-1]+=a[i]*b[j];
	for(i=1;i<c[0];i++)
	{
		c[i+1]+=c[i]/10;
		c[i]%=10;		
	}
	while(!c[c[0]])
		c[0]--;
	memcpy(a,c,sizeof(c));
	return;
}
void plu(int *a,int *b)
{
	int i;
	a[0]=max(a[0],b[0]);
	for(i=1;i<=a[0];i++)
		a[i]+=b[i];
	for(i=1;i<=a[0];i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	while(a[a[0]+1])
		a[0]++;
	return;
}
void divide(int m,int t)
{
	int i;
	for(i=2;i<=m;i++)
		while(m%i==0)
	    {
			e[i]+=t;
			m/=i;
		}
	return;
}
void C(int m,int p)
{
	int i,j;
	memset(c,0,sizeof(c));
	c[0]=c[1]=1;
	memset(e,0,sizeof(e));
	for(i=m;i>m-p;i--)
		divide(i,1);
	for(i=p;i>0;i--)
		divide(i,-1);
	for(i=2;i<50;i++)
		while(e[i]--)
			smul(c,i);
	return;
}
void print(int *p)
{
	for(int i=p[0];i>1;i--)
		printf("%d",p[i]);
	printf("%d",p[1]);
	printf("----%d\n",p[0]);
	return;
}
long long pw(int x)
{
	return x==0?1:2*pw(x-1);
}
//F(n)=¡Æ (F(k)*F(n-k)* C(n-2,k-1)*(2^k-1) | 1<=k<n)
int main()
{
	freopen("C:\\c.out","w",stdout);
	int i,j,k;
	int dx[2]={1,2};
	er[0][0]=er[0][1]=0;
	er[1][0]=er[1][1]=1;
	for(i=2;i<51;i++)
	{
		memcpy(er[i],er[i-1],sizeof(er[i]));
		dmul(er[i],dx);
		plu(er[i],er[1]);
	}
//	scanf("%d",&n);
	f[1][0]=f[1][1]=1;
	for(i=2;i<51;i++)
	{
		for(k=1;k<i;k++)
		{
			memset(a,0,sizeof(a));
			memcpy(b,f[k],sizeof(f[k]));
			dmul(b,f[i-k]);
			C(i-2,k-1);
			dmul(b,c);
			dmul(b,er[k]);
			plu(f[i],b);
		}
		print(f[i]);
	}
	return 0;
}
