#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
string s[15],c;
int n,m;
int i,j,k,ans;
int p[1020];
int r[1020];
int f[100020];
int S(int x)
{
	int i,j,k;
	int sum=0;
	memset(f,0,sizeof(f));
	f[0]=1;
	for(i=0;i<m;i++)
		if(r[i]==x)
		{
			for(j=50000;j>=p[i];j--)
				if(f[j-p[i]])
					f[j]=1;
			sum+=p[i];
		}
	for(i=sum/2;i>=0;i--)
		if(f[i])
			break;
	return max(i,sum-i);
}
int main()
{
	while(scanf("%d %d",&n,&m)&&n+m)
	{
		for(i=0;i<n;i++)
			cin>>s[i];
		for(i=0;i<m;i++)
		{
			cin>>p[i]>>c;
			for(j=0;j<n;j++)
				if(c==s[j])
					break;
			r[i]=j;
		}
		ans=0;
		for(i=0;i<n;i++)
			ans+=S(i);
		printf("%d\n",ans);
	}
	return 0;
}