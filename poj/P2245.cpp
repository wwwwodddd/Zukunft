#include<stdio.h>
#include<algorithm>
using namespace std;
int n,a[20],v[20];
int main()
{
	for(;scanf("%d",&n),n;)
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		for(int i=6;i<n;i++)
			v[i]=1;
		do
		{
			for(int i=0;i<n;i++)
				if(!v[i])
					printf("%d ",a[i]);
			puts("");
		}
		while(next_permutation(v,v+n));
		puts("");
	}
	return 0;
}
