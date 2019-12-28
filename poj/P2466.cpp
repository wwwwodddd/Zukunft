#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100],s[100],n;
bool v[100];
int i,j,k,p,q;
int m;
int main()
{
	while(scanf("%d",&n)+1)
	{
		m=n*(n-1)/2;
		for(i=1;i<=m;i++)
			scanf("%d",&s[i]);
		sort(s+1,s+1+m);
		for(i=3;i<=m;i++)
		{
			memset(v,0,sizeof(v));
			a[1]=s[1]+s[2]-s[i];
			a[2]=s[1]-s[2]+s[i];
			a[3]=s[2]-s[1]+s[i];
			if(a[1]&1||a[2]&1||a[3]&1)
				continue;
			a[1]/=2;
			a[2]/=2;
			a[3]/=2;
			v[1]=v[2]=v[i]=1;
			for(j=4;j<=n;j++)
			{
				for(k=3;k<=m;k++)
					if(!v[k])
						break;
				a[j]=s[k]-a[1];
				v[k]=1;
				for(p=2;p<j;p++)
				{
					int sum=a[p]+a[j];
					for(q=k+1;q<=m;q++)
						if(s[q]==sum)
							break;
					if(q>m)
						goto s;
					v[q]=1;
				}
			}
			break;
			s:
			continue;
		}
		if(i<=m)
		{
			for(i=1;i<=n;i++)
				printf("%d ",a[i]);
			printf("\n");
		}
		else
			printf("Impossible\n");
	}
}
