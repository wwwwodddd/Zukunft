#include<stdio.h>
#include<iostream>
using namespace std;
int f[160][160][160],a[160][160][160],b[160][160][160];
int h[30000],lt[30000],rt[30000],s[30000];
int tmp,i,j,k,p,q,r,pp,qq,rr,re,ans,ss;
char ch;
int calc()
{
	re=0;
	for(i=1;i<=p;i++)
		for(j=q;j>0;j--)
			for(k=r;k>0;k--)
				if(a[i][j][k])
					f[i][j][k]=min(f[i][j+1][k+1],min(f[i][j+1][k],f[i][j][k+1]))+1;
				else
					f[i][j][k]=0;
	for(j=1;j<=q;j++)
		for(k=1;k<=r;k++)
		{
			for(i=1;i<=p;i++)
				h[i]=f[i][j][k];
			ss=0;
			for(i=1;i<=p;i++)
			{
				while(ss>0&&h[s[ss]]>=h[i])
					ss--;
				lt[i]=s[ss]+1;
				s[++ss]=i;
			}
			ss=1;
			s[ss]=p+1;h[p+1]=0x80000000;
			for(i=p;i>0;i--)
			{
				while(ss>0&&h[s[ss]]>=h[i])
					ss--;
				rt[i]=s[ss]-1;
				re=max(re,h[i]*(rt[i]-lt[i]+1));
				s[++ss]=i;
			}
		}
	return re;
}
int main()
{
	scanf("%d%d%d",&qq,&pp,&rr);
	for(i=1;i<=pp;i++)
		for(j=1;j<=qq;j++)
			for(k=1;k<=rr;k++)
			{
				cin>>ch;
				b[i][j][k]=(ch=='N');
			}
	p=pp;q=qq;r=rr;
	for(i=1;i<=p;i++)
		for(j=1;j<=q;j++)
			for(k=1;k<=r;k++)
				a[i][j][k]=b[i][j][k];
	ans=max(calc(),ans);
	p=qq;q=pp;r=rr;
	for(i=1;i<=p;i++)
		for(j=1;j<=q;j++)
			for(k=1;k<=r;k++)
				a[i][j][k]=b[j][i][k];
	ans=max(calc(),ans);
	p=rr;q=qq;r=pp;
	for(i=1;i<=p;i++)
		for(j=1;j<=q;j++)
			for(k=1;k<=r;k++)
				a[i][j][k]=b[k][j][i];
	ans=max(calc(),ans);
	printf("%d",4*ans);
	return 0;
}