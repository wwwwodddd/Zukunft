#include<stdio.h>
#include<iostream>
using namespace std;
int n,m,s[1048580],f[1048580];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",s+(1<<i)),s[1<<i]*=-1;
	scanf("%d",&m),m+=n;
	for(int i=n;i<m;i++)
		scanf("%d",s+(1<<i));
	for(int i=1;i<1<<m;i++)
	{
		s[i]=s[i&-i]+s[i-(i&-i)];
		for(int j=0;j<m;j++)
			if(i>>j&1)
				f[i]=max(f[i],f[i^1<<j]);
		f[i]+=s[i]==0;
	}
	printf("%d\n",m-2*f[(1<<m)-1]);
}
