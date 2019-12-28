#include<iostream>
using namespace std;
const int x=31250000;
short head[2*x+20];
int a,b,c,d,e,i,j,k,u,v,t;
long long res;
int main()
{
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	for(u=-50;u<=50;u++)
		for(v=-50;v<=50;v++)
			if(u!=0&&v!=0)
			{
				t=d*u*u*u+e*v*v*v+x;
				head[t] ++;
			}
	for(i=-50;i<=50;i++)
		for(j=-50;j<=50;j++)
			for(k=-50;k<=50;k++)
				if(i!=0&&j!=0&&k!=0)
				{
					t=-(a*i*i*i+b*j*j*j+c*k*k*k)+x;
					res+=head[t];
				}
	printf("%d\n",res);
	return 0;
}
