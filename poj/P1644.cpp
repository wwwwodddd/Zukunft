#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int l=-55555;
int n,m,t,i,j,q,h,f,ll,v;
char s[500];
char ss[50];
double a[55][55];
int p[55];
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		cin>>m>>t;
		for(i=1;i<=m;i++)
		{
			scanf("%s",s);
			if(s[0]=='L')
				p[i]=l;
			else
				sscanf(s,"%d",p+i);
		}
		p[0]=0;
		p[m+1]=0;
		a[0][0]=1;
		for(i=0;i<t;i++)
		{
			for(j=0;j<=m;j++)
				if(a[i][j])
				{
					if(p[j+1]==l)
						a[i+2][j+1]+=a[i][j]/2;
					else
					{
						h=j+1+p[j+1];
						if(h<0)
							h=0;
						if(h>m+1)
							h=m+1;
						a[i+1][h]+=a[i][j]/2;
					}
					if(p[j+2]==l)
						a[i+2][j+2]+=a[i][j]/2;
					else
					{
						h=j+2+p[j+2];
						if(h<0)
							h=0;
						if(h>m+1)
							h=m+1;
						a[i+1][h]+=a[i][j]/2;
					}
				}
			a[i+1][m+1]+=a[i][m+1];
		}
		if(fabs(a[t][m+1]-0.5000)<0.0000001)
				printf("Push. 0.5000\n");
		else
		{
				f=a[t][m+1]*10000000;
				if(f>5000000)
					printf("Bet for. %.4f\n",a[t][m+1]);
				else
					printf("Bet against. %.4f\n",a[t][m+1]);
		}
	}
	return 0;
}