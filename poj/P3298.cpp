#include<iostream>
using namespace std;
int i,k,n,t,z,a[30020];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		for(z=i=1,k=a[0];i<n;i++)
			if(k<a[i]&&z%2==1||k>a[i]&&z%2==0)
				k=a[i];
			else if(k>a[i]&&z%2==1||k<a[i]&&z%2==0)
				k=a[i],z++;
		printf("%d\n",z);
	}
	return 0;
}