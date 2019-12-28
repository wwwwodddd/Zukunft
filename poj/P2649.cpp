#include<iostream>
using namespace std;
int n,m;
int solve(int m)
{
	int i,j,x,y,z=0;
	if(m==0)
		return 0;
	if(n>=m)
		return 1;
	for(i=2;i*i<=m&&!z;i++)
		if(m%i==0)
		{
			for(x=0;m%i==0;m/=i)
				x++;
			for(y=0,j=n;j;j/=i)
				y+=j/i;
			if(y<x)
				z=1;
		}
	if(z||m>n)
		return 0;
	else
		return 1;
}
int main()
{
	while(scanf("%d %d",&n,&m)+1)
		printf("%d %s %d!\n",m,solve(m)?"divides":"does not divide",n);
	return 0;
}