#include<iostream>
#include<algorithm>
using namespace std;
long long a[10005],s;
int b[10005];
int c[5];
int n,l;
int main()
{
	int i,j,k,mx,z;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<5;j++)
				scanf("%d",&c[j]);
			sort(c,c+5);
			s=0;
			for(j=0;j<5;j++)
				s=s*1000+c[j];
			a[i]=s;
		}
		sort(a,a+n);
		l=mx=z=0;
		a[n]=-1;
		k=1;
		for(i=1;i<=n;i++)
		{
			if(a[i]==a[i-1])
				k++;
			else
			{
				b[l++]=k;
				if(k>mx)
					mx=k;
				k=1;
			}
		}
		for(i=0;i<l;i++)
			if(b[i]==mx)
				z+=mx;
		printf("%d\n",z);
	}
	return 0;
}