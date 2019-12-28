#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
bool q[5020],p[5020],w[5020];
int n,m=-1,i,j,k;
char s[2];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		if(s[0]=='B')
			q[i]=1;
		else
			q[i]=0;
		p[i]=q[i]^q[i-1];
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n;j++)
			w[j]=p[j];
		int sum=0;
		for(j=1;j+i-1<=n;j++)
			if(w[j])
			{
					w[j]=0;
					w[j+i]^=1;
					sum++;
			}
		for(j=1;j<=n;j++)
			if(w[j])
				break;
		if(j>n&&(m==-1||sum<m))
		{
			m=sum;
			k=i;
		}
	}
	printf("%d %d\n",k,m);
	return 0;
}
