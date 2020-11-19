#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,f[420],t[420],d[420][420];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",t+i);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",d[i]+j);
	for(int i=0;i<n;i++)
		if(d[0][i]<=t[i])
			f[i]=1;
	for(int o=1;o;)
	{
		o=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j&&f[j]<f[i]+1&&t[i]+d[i][j]<=t[j])
					f[j]=f[i]+1,o=1;
	}
	printf("%d\n",*max_element(f,f+n));
	return 0;
}

