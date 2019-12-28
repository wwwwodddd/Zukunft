#include<iostream>
using namespace std;
double mw,mi,tw,ti,ri,rw,rt,Q,M;
int main()
{
	while(scanf("%lf %lf %lf %lf",&mw,&mi,&tw,&ti),mw+mi+tw+ti)
	{
		Q=mw*tw*4.19+mi*ti*2.09+mw*335.;
		M=mw+mi;
		if(Q<0)
		{
			rw=0;
			ri=M;
			rt=Q/M/2.09;
		}
		else if(Q>M*335.)
		{
			rw=M;
			ri=0;
			rt=(Q-M*335.)/M/4.19;
		}
		else
		{
			rw=Q/335.;
			ri=M-rw;
			rt=0;
		}
		printf("%.1lf g of ice and %.1lf g of water at %.1lf C\n",ri,rw,rt);
	}
	return 0;
}