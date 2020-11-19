#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int t1[6020],t2[6020],t3[6020],f[100020],n,s,z=0xffffff;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",t1+i,t2+i,t3+i);
		if(!t1[i])
			t1[i]=0xffff;
		if(!t2[i])
			t2[i]=0xffff;
		if(!t3[i])
			t3[i]=0xffff;
		s+=min(t1[i],min(t2[i],t3[i]));
	}
	memset(f,0x3f,sizeof f);
	f[0]=0;
	for(int i=0;i<n;i++)
		for(int j=s;j>=0;j--)
			f[j]=min(f[j]+t2[i],min(j>=t1[i]?f[j-t1[i]]:0x3f3f3f3f,j>=t3[i]?f[j-t3[i]]+t3[i]:0x3f3f3f3f));
	for(int i=0;i<=s;i++)
		z=min(z,max(i,f[i]));
	printf("%d\n",z);
	return 0;
}
