#include<stdio.h>
#include<iostream>
#define fr(i,n) for(int i=0;i<n;i++)
using namespace std;
int a[3][55],c[3];
long long z[2];
long long work(int x,int n)
{
	long long re=0,pw=1LL<<55;
	int i=0;
	for (;i<n&&a[x][i]==a[x][0];i++)
		if(a[x][i]==0)
			re+=pw;
		else
			re-=pw;
	for(pw>>=1;i<n;i++,pw>>=1)
		if(a[x][i]==0)
			re+=pw;
		else
			re-=pw;
	return re;
}
int main()
{
	char o[12];
	int t,k;
	for(scanf("%d",&t);t--;)
	{
		scanf("%*s %d",&k);
		fr(s,2)
		{
			fr(i,3)
				scanf("%d",&c[i]);
			fr(i,3)
				fr(j,c[i])
				{
					scanf("%s",o);
					if(*o=='W')
						a[i][j]=0;
					else
						a[i][j]=1;
				}
			z[s]=0;
			fr(i,3)
				z[s]+=work(i,c[i]);
		}
		printf("Test %d: ",k);
		puts(z[0]<z[1]?"No":"Yes");
	}
	return 0;
}
