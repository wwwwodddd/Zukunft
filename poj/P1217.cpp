#include<stdio.h>
#define F(i,j) f[i][(j)+110]
double f[30][220];
double x[30];
double y[30];
int n;
int a[6]={-3,-1,0,1,2,3};
double b[6]={0.0625,0.125,0.375,0.25,0.125,0.0625};
using namespace std;
int main()
{
	F(0,0)=1;
	puts("Round   A wins    B wins    Tie");
	for(int i=1;i<=20;i++)
	{
		for(int j=-100;j<100;j++)
		{
			for(int k=0;k<6;k++)
				F(i,j)+=F(i-1,j-a[k])*b[k];
			if(j>0)
				x[i]+=F(i,j);
			if(j<0)
				y[i]+=F(i,j);
		}
		printf("%5d   %7.4f%% %8.4f%% %8.4f%%\n",i,x[i]*100,y[i]*100,F(i,0)*100);
	}
	while(1);
	return 0;
}
