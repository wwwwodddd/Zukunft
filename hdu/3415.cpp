#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int t,n,k,z,st,ed;
int s[200020];
int q[200020],b,f;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i),s[n+i]=s[i];
		for(int i=0;i<2*n;i++)
			s[i+1]+=s[i];
		z=0xc0000000;
		q[b=f=0]=0;
		for(int i=1;i<=2*n;i++)
		{
			while(i-q[b]>k)
				b++;
			if(s[i]-s[q[b]]>z)
			{
				z=s[i]-s[q[b]];
				st=q[b]+1;
				ed=i;
			} 
			while(b<=f&&s[i]<s[q[f]])
				f--;
			q[++f]=i;
		}
		printf("%d %d %d\n",z,st,(ed-1)%n+1);
	}
	return 0;
}
