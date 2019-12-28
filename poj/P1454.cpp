#include<iostream>
using namespace std;
int a[1020],v[15];
int i,j,k,n;
int main()
{
	while(scanf("%d",&n)&&n)
	{
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		a[0]=1;
		for(i=2;i<=n;i++)
		{
			for(j=0;j<1000;j++)
				a[j]*=i;
			for(j=0;j<1000;j++)
			{
				a[j+1]+=a[j]/10;
				a[j]%=10;
			}
		}
		k=1000;
		while(!a[k])
			k--;
		for(i=0;i<=k;i++)
			v[a[i]]++;
		printf("%d! --\n   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",n,v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9]);
		
	}
	return 0;
}
