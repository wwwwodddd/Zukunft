#include<iostream>
using namespace std;
int v[1000020];
int i,j,k,x,y,z,n,cnt,ans;
int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		memset(v,0,sizeof(v));
		cnt=ans=0;
		for(i=1;i*i*2<=n;i++)
			for(j=i+1;j*j<=n;j++)
			{
				x=j*j-i*i;
				y=2*j*i;
				z=i*i+j*j;
				if(z>n)
					break;
				if(gcd(x,y)==1)
				{
					cnt++;
					for(k=1;k*z<=n;k++)
						v[x*k]=v[y*k]=v[z*k]=1;
				}
			}
		for(i=1;i<=n;i++)
			if(!v[i])
				ans++;
		printf("%d %d\n",cnt,ans);
	}
	return 0;
}