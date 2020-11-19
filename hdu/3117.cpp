#include<stdio.h>
#include<iostream>
#include<math.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int>ii;
int f[40],n,p=10000;
int G(int n)
{
	double x=0.20898764024997873*n-0.3494850021680094;
	x=x-(int)x+3;
	return (int)pow(10,x);
}
ii F(int x)
{
	if(x==0)
		return make_pair(0,1);
	else if(x%2==1)
	{
		ii a=F(x-1);
		return make_pair(a.Y,(a.X+a.Y)%p);
	}
    else
    {
		ii a=F(x/2);
		return make_pair((a.X*(2*a.Y-a.X))%p,(a.X*a.X+a.Y*a.Y)%p);
	}
}int main()
{
	f[1]=1;
	for(int i=2;i<40;i++)
		f[i]=f[i-1]+f[i-2];
	while(~scanf("%d",&n))
	{
		if(n<40)
			printf("%d\n",f[n]);
		else
			printf("%d...%04d\n",G(n),(F(n).X+p)%p);
	}
	return 0;
}
