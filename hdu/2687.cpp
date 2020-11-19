#include<stdio.h>
#include<string.h>
int n,m;
int a[12][12],s[12][12];
void rtt()
{
	int _[12][12];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			_[j][n-i-1]=a[i][j];
//			_[n-j-1][i]=a[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=_[i][j];
}
void add(int a[12][12],int b[12][12])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]+=b[i][j];
}
int main()
{
	while(~scanf("%d",&n))
	{
		memset(s,0,sizeof s);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",a[i]+j);
		scanf("%d",&m),m++;
		for(int i=0;i<4;i++)
		{
			add(s,a);
			rtt();
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				s[i][j]*=m/4;
		for(int i=0;i<m%4;i++)
		{
			add(s,a);
			rtt();
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				printf("%d%c",s[i][j],j==n-1?'\n':' ');
	}
	return 0;
}
