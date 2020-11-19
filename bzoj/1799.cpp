#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;
ll L,R;
ll f[2][163][163][163],t[20];
int c,d;
ll F(ll x)
{
	ll _=c=0;
	if(x==t[18])
		_++,x--;
	memset(f,0,sizeof f);
	for(ll i=x;i;i/=10)
		c++,d+=i%10;
	for(int i=1;i<=9*c;i++)
		f[1][0][i][0]=1;
	for(int i=0;i<c;i++)
	{
		int s=i==c-1,e=x/t[i]%10+!i;
		d-=x/t[i]%10;
		for(int j=s;j<e;j++)
			for(int k=0,l;k<=9*i;k++)
			{
				l=d+j+k;
				_+=f[i-1&1][k][l][-(x/t[i+1]*t[i+1]+j*t[i]-1)%l+l-1];
			}
		if(i==c-1)
			for(int j=0;j<=9*i;j++)
				_+=f[i-1&1][j][j][0];
		else
			for(int j=0;j<=9*i;j++)
				for(int k=j;k<=9*c;k++)
					for(int l=0;l<k;l++)
						if(f[i-1&1][j][k][l])
						{
							for(int m=0;m<10;m++)
								f[i&1][j+m][k][(l+m*t[i])%k]+=f[i-1&1][j][k][l];
							f[i-1&1][j][k][l]=0;
						}
	}
	return _;
}
int main()
{
	ios::sync_with_stdio(false);
	for(int i=t[0]=1;i<19;i++)
		t[i]=t[i-1]*10;
	cin>>L>>R;
	cout<<F(R)-F(L-1)<<endl;
	return 0;
}
